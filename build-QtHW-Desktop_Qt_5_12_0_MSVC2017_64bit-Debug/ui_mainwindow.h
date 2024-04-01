/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_7;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_2;
    QGroupBox *groupBox_6;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QCustomPlot *frame;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectButton;
    QPushButton *computeButton;
    QPushButton *breakButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(741, 655);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(170, 50));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 30, 20));
        label_3->setMinimumSize(QSize(30, 20));
        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 10, 113, 30));
        lineEdit_2->setMinimumSize(QSize(110, 30));

        gridLayout->addWidget(groupBox_5, 1, 1, 1, 1);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(190, 50));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 10, 50, 20));
        label_4->setMinimumSize(QSize(50, 20));
        plainTextEdit_2 = new QPlainTextEdit(groupBox_7);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(70, 10, 111, 31));
        plainTextEdit_2->setMinimumSize(QSize(110, 30));

        gridLayout->addWidget(groupBox_7, 1, 2, 1, 1);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(190, 50));
        plainTextEdit = new QPlainTextEdit(groupBox_6);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(70, 10, 111, 31));
        plainTextEdit->setMinimumSize(QSize(110, 30));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 51, 21));
        label_2->setMinimumSize(QSize(50, 20));

        gridLayout->addWidget(groupBox_6, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(230, 110));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(14, 17, 145, 30));
        comboBox->setMinimumSize(QSize(131, 30));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(groupBox, 0, 0, 2, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(530, 380));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QCustomPlot(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(650, 280));

        verticalLayout->addWidget(frame);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(400, 70));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(180, 50));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 31, 20));
        label->setMinimumSize(QSize(30, 20));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 10, 113, 30));
        lineEdit->setMinimumSize(QSize(110, 30));

        gridLayout->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(550, 100));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        connectButton = new QPushButton(groupBox_3);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setMinimumSize(QSize(80, 25));
        connectButton->setMaximumSize(QSize(80, 25));
        connectButton->setCheckable(false);

        horizontalLayout->addWidget(connectButton);

        computeButton = new QPushButton(groupBox_3);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));
        computeButton->setEnabled(false);
        computeButton->setMinimumSize(QSize(80, 25));
        computeButton->setMaximumSize(QSize(80, 25));

        horizontalLayout->addWidget(computeButton);

        breakButton = new QPushButton(groupBox_3);
        breakButton->setObjectName(QString::fromUtf8("breakButton"));
        breakButton->setEnabled(false);
        breakButton->setMinimumSize(QSize(80, 25));
        breakButton->setMaximumSize(QSize(80, 25));

        horizontalLayout->addWidget(breakButton);

        exitButton = new QPushButton(groupBox_3);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setEnabled(false);
        exitButton->setMinimumSize(QSize(80, 25));
        exitButton->setMaximumSize(QSize(80, 25));

        horizontalLayout->addWidget(exitButton);


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_7->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_5->setTitle(QString());
        label_3->setText(QApplication::translate("MainWindow", "Xn", nullptr));
        groupBox_7->setTitle(QString());
        label_4->setText(QApplication::translate("MainWindow", "Order", nullptr));
        groupBox_6->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "nPoints", nullptr));
        groupBox->setTitle(QString());
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Sine integral", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Cosine integral", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Bessel Function", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Fresnel Integral S", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "Fresnel Integral C", nullptr));

        groupBox_2->setTitle(QString());
        groupBox_4->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "X0", nullptr));
        groupBox_3->setTitle(QString());
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        computeButton->setText(QApplication::translate("MainWindow", "Compute", nullptr));
        breakButton->setText(QApplication::translate("MainWindow", "Break", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
