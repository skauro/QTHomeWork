// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocalSocket>
#include <QVector>
#include <QtWidgets>
#include <QPointF>
#include <QObject>
#include "qcustomplot.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connectToServer();
    void disconnectFromServer();
    void sendCommandToServer();
    void handleSocketError(QLocalSocket::LocalSocketError socketError);
    void processServerResponse();
    void setupPlot();
    void exit();

private:
    Ui::MainWindow *ui;
    QLocalSocket *socket;
    QCustomPlot *customPlot;

    QByteArray sendSin(double dxstart,double dxend,int npoints);
    QByteArray sendCos(double dxstart,double dxend,int npoints);
    QByteArray sendBes(double dxstart,double dxend,int npoints,int order);
    QByteArray sendFreS(double dxstart,double dxend,int npoints);
    QByteArray sendFreC(double dxstart,double dxend,int npoints);
    void displayMessage(const QString &message);
    QByteArray prepareCommand(const QString &functionType, double rangeStart, double rangeEnd, int numPoints, int besselOrder);
    QVector<QPointF> parseServerResponse(const QByteArray &response);
    void plotGraph(const QVector<QPointF> &data);
};
#endif // MAINWINDOW_H
