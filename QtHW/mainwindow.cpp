#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QTextCodec>
#include "qcustomplot.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new QLocalSocket(this)),
    customPlot(new QCustomPlot(this))
{
    ui->setupUi(this);

    // Connect signals and slots

    connect(socket, QOverload<QLocalSocket::LocalSocketError>::of(&QLocalSocket::error), this, &MainWindow::handleSocketError);
    connect(socket, &QLocalSocket::readyRead, this, &MainWindow::processServerResponse);

    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::connectToServer);
    connect(ui->breakButton, &QPushButton::clicked, this, &MainWindow::disconnectFromServer);
    connect(ui->computeButton, &QPushButton::clicked, this, &MainWindow::sendCommandToServer);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exit);
}



void MainWindow::exit()
{
    QApplication::exit();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToServer()
{
    socket->connectToServer("\\\\.\\pipe\\ICS0025");
    if (!socket->waitForConnected()) {
        displayMessage("Error: Failed to connect to server.");
    } else {

        displayMessage("Connected to server.");
        ui->connectButton->setEnabled(false);
        ui->breakButton->setEnabled(true);
        ui->computeButton->setEnabled(true);
    }
}

void MainWindow::disconnectFromServer()
{
    QByteArray bytearr;


    char * stopCommand = (char*)"Stop\0";

    bytearr.append(14);    //this message is going to be 14 bytes long
    bytearr.append('\0');bytearr.append('\0');bytearr.append('\0');

    for(int i=0; i<4; i++){
        bytearr.append(stopCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');bytearr.append('\0');


    if (this->socket->state()==QLocalSocket::ConnectedState){

        socket->write(bytearr, 14);

        socket->disconnectFromServer();

        ui->computeButton->setEnabled(false);
        ui->connectButton->setEnabled(false);
        ui->exitButton->setEnabled(true);
        ui->breakButton->setEnabled(false);


        displayMessage("Disconnected from pipe server");
    }else{
        displayMessage("ERROR: "+socket->errorString());
    }
}

void MainWindow::sendCommandToServer()
{
    QString functionType = ui->comboBox->currentText();
    double rangeStart = ui->lineEdit->text().toDouble();
    double rangeEnd = ui->lineEdit_2->text().toDouble();
    QString numPointsStr = ui->plainTextEdit->toPlainText();
    bool ok;
    int numPoints = numPointsStr.toInt(&ok);
    QString besselOrderStr = ui->plainTextEdit_2->toPlainText();
    bool ok1;
    int besselOrder = besselOrderStr.toInt(&ok1);
    if (!ok || !ok1) {
        displayMessage("Error: Invalid parameter values.");
        return;
    }

    QByteArray command = prepareCommand(functionType, rangeStart, rangeEnd, numPoints, besselOrder);
    socket->write(command);
}

void MainWindow::handleSocketError(QLocalSocket::LocalSocketError socketError)
{
    if (socketError == QLocalSocket::ConnectionRefusedError) {
        displayMessage("Error: Connection refused by server.");
    } else if (socketError == QLocalSocket::UnknownSocketError) {
        displayMessage("Error: Socket error occurred.");
    }
}


void MainWindow::processServerResponse()
{

    QByteArray bytearr = socket->readAll();
    QDataStream dataStream(bytearr);
    dataStream.setByteOrder(QDataStream::LittleEndian);

    int len = 0;
    dataStream >> len;

    if (bytearr.length() != len) {
        QMessageBox::critical(this,"ERROR", "Invalid length!");
        return;
    }

    QString responseString;

    while (true) {
        ushort responseChar = 0;
        dataStream >> responseChar;
        if (responseChar == 0)
            break;
        responseString.append(QChar(responseChar));
    }



    if (responseString != "Curve") {
        displayMessage("Response message did not contain \"Curve\" ERROR");
        ui->textBrowser->setText(responseString);
    }
    else {
        displayMessage("successfull response");
        ui->textBrowser->setText(responseString);

        QVector<double> vXpoints;
        QVector<double> vYpoints;

        double minX = 0;
        double maxX = 0;
        double minY = 0;
        double maxY = 0;

        while (!dataStream.atEnd()) {

            double dfX, dfY;
            dataStream >> dfX >> dfY;

            vXpoints.push_back(dfX);
            vYpoints.push_back(dfY);

            //  find minimum and maximum

            if (dfX > maxX) maxX = dfX;
            if (dfX < minX) minX = dfX;
            if (dfY > maxY) maxY = dfY;
            if (dfY < minY) minY = dfY;

        }

        QString strFunctionName = ui->comboBox->currentText();

        ui->frame->addGraph();

        ui->frame->graph(0)->setData(vXpoints, vYpoints);

        ui->frame->graph(0)->setPen(QPen(Qt::black));
        ui->frame->graph(0)->setLineStyle(QCPGraph::lsLine);

        ui->frame->graph(0)->setName(strFunctionName);

        ui->frame->xAxis->setLabel("X coords");
        ui->frame->yAxis->setLabel("Y coords");

        ui->frame->xAxis->setRange(minX, maxX);
        ui->frame->yAxis->setRange(minY, maxY);

        ui->frame->setInteraction(QCP::iRangeDrag, true);
        ui->frame->setInteraction(QCP::iRangeZoom, true);


        displayMessage("Function :  ");

        ui->frame->replot();
    }
}


void MainWindow::displayMessage(const QString &message)
{
    ui->textBrowser->setText(message);
}

QByteArray MainWindow::prepareCommand(const QString &functionType, double rangeStart, double rangeEnd, int numPoints, int besselOrder)
{
    if(ui->comboBox->currentIndex() == 0 ){
        return sendSin(rangeStart, rangeEnd, numPoints);
    }
    else if(ui->comboBox->currentIndex() == 1){
        return sendCos(rangeStart, rangeEnd, numPoints);
    }
    else if(ui->comboBox->currentIndex() == 2){
        return sendBes(rangeStart, rangeEnd, numPoints, besselOrder);
    }
    else if(ui->comboBox->currentIndex() == 3){
        return sendFreS(rangeStart, rangeEnd, numPoints);
    }
    else if(ui->comboBox->currentIndex() == 4){
        return sendFreC(rangeStart, rangeEnd, numPoints);
    }
    return QByteArray();
}

QByteArray MainWindow::sendSin(double dxstart,double dxend,int npoints) {
    int nBytes = 52;
    QByteArray bytearr;
    char * sineCommand = (char *) "Sine integral\0";

    for(int i=0; i<4; i++){
        bytearr.append(nBytes<<(8*i));
    }

    for(int i=0; i<13; i++){
        bytearr.append(sineCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');

    bytearr.append('\0');


    char * tmparr = (char *)&dxstart;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    tmparr = (char *)&dxend;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(npoints<<(8*i));
    }

    return bytearr;
}

QByteArray MainWindow::sendCos(double dxstart,double dxend,int npoints) {
    int nBytes = 56;
    QByteArray bytearr;
    char * cosineCommand = (char *) "Cosine integral\0";

    for(int i=0; i<4; i++){
        bytearr.append(nBytes<<(8*i));
    }

    for(int i=0; i<15; i++){
        bytearr.append(cosineCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');

    bytearr.append('\0');


    char * tmparr = (char *)&dxstart;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    tmparr = (char *)&dxend;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(npoints<<(8*i));
    }

    return bytearr;
}

QByteArray MainWindow::sendBes(double dxstart,double dxend,int npoints,int order) {
    int nBytes = 60;
    QByteArray bytearr;
    char * besselCommand = (char *) "Bessel function\0";

    for(int i=0; i<4; i++){
        bytearr.append(nBytes<<(8*i));
    }

    for(int i=0; i<15; i++){
        bytearr.append(besselCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');

    bytearr.append('\0');


    char * tmparr = (char *)&dxstart;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    tmparr = (char *)&dxend;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(npoints<<(8*i));
    }

    // only bessel requires order so we added here
    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(order<<(8*i));
    }


    return bytearr;
}

QByteArray MainWindow::sendFreS(double dxstart,double dxend,int npoints) {
    int nBytes = 62;
    QByteArray bytearr;
    char * fresnelSCommand = (char *) "Fresnel integral S\0";

    for(int i=0; i<4; i++){
        bytearr.append(nBytes<<(8*i));
    }

    for(int i=0; i<18; i++){
        bytearr.append(fresnelSCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');

    bytearr.append('\0');


    char * tmparr = (char *)&dxstart;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    tmparr = (char *)&dxend;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(npoints<<(8*i));
    }

    return bytearr;
}

QByteArray MainWindow::sendFreC(double dxstart,double dxend,int npoints) {
    int nBytes = 62;
    QByteArray bytearr;
    char * fresnelSCommand = (char *) "Fresnel integral C\0";

    for(int i=0; i<4; i++){
        bytearr.append(nBytes<<(8*i));
    }

    for(int i=0; i<18; i++){
        bytearr.append(fresnelSCommand[i]);
        bytearr.append('\0');
    }

    bytearr.append('\0');

    bytearr.append('\0');


    char * tmparr = (char *)&dxstart;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    tmparr = (char *)&dxend;
    for(unsigned int i=0; i<sizeof(double); i++){
        bytearr.append(tmparr[i]);
    }

    for(unsigned int i=0; i<sizeof(int); i++){
        bytearr.append(npoints<<(8*i));
    }

    return bytearr;
}

