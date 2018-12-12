/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QGridLayout *gridLayout_3;
    QSlider *horizontalSliderMin;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLCDNumber *lcdNumberMin;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLCDNumber *lcdNumberMax;
    QSlider *horizontalSliderMax;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSliderTiming;
    QLabel *label_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonPut;
    QPushButton *pushButtonStop;
    QTextBrowser *textBrowser;
    QLabel *labelStatus;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(559, 372);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 2);

        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        gridLayout_5->addWidget(pushButtonConnect, 1, 0, 1, 1);

        pushButtonDisconnect = new QPushButton(centralWidget);
        pushButtonDisconnect->setObjectName(QStringLiteral("pushButtonDisconnect"));

        gridLayout_5->addWidget(pushButtonDisconnect, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSliderMin = new QSlider(centralWidget);
        horizontalSliderMin->setObjectName(QStringLiteral("horizontalSliderMin"));
        horizontalSliderMin->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSliderMin, 0, 0, 1, 1);

        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        lcdNumberMin = new QLCDNumber(splitter_3);
        lcdNumberMin->setObjectName(QStringLiteral("lcdNumberMin"));
        lcdNumberMin->setSegmentStyle(QLCDNumber::Flat);
        splitter_3->addWidget(lcdNumberMin);

        gridLayout_3->addWidget(splitter_3, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 90);

        gridLayout_6->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        lcdNumberMax = new QLCDNumber(splitter_2);
        lcdNumberMax->setObjectName(QStringLiteral("lcdNumberMax"));
        lcdNumberMax->setSegmentStyle(QLCDNumber::Flat);
        splitter_2->addWidget(lcdNumberMax);

        gridLayout->addWidget(splitter_2, 0, 1, 1, 1);

        horizontalSliderMax = new QSlider(centralWidget);
        horizontalSliderMax->setObjectName(QStringLiteral("horizontalSliderMax"));
        horizontalSliderMax->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderMax, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 90);
        gridLayout->setColumnStretch(1, 10);

        gridLayout_6->addLayout(gridLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSliderTiming = new QSlider(centralWidget);
        horizontalSliderTiming->setObjectName(QStringLiteral("horizontalSliderTiming"));
        horizontalSliderTiming->setMinimum(1);
        horizontalSliderTiming->setMaximum(60);
        horizontalSliderTiming->setPageStep(1);
        horizontalSliderTiming->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSliderTiming);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);


        gridLayout_6->addLayout(horizontalLayout, 3, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButtonPut = new QPushButton(centralWidget);
        pushButtonPut->setObjectName(QStringLiteral("pushButtonPut"));

        gridLayout_4->addWidget(pushButtonPut, 0, 0, 1, 1);

        pushButtonStop = new QPushButton(centralWidget);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));

        gridLayout_4->addWidget(pushButtonStop, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 4, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_7->addWidget(textBrowser, 0, 1, 1, 1);

        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        gridLayout_7->addWidget(labelStatus, 1, 0, 1, 2);

        gridLayout_7->setColumnStretch(0, 50);
        gridLayout_7->setColumnStretch(1, 50);

        verticalLayout->addLayout(gridLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 559, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderMin, SIGNAL(valueChanged(int)), lcdNumberMin, SLOT(display(int)));
        QObject::connect(horizontalSliderMax, SIGNAL(valueChanged(int)), lcdNumberMax, SLOT(display(int)));
        QObject::connect(horizontalSliderTiming, SIGNAL(valueChanged(int)), label_4, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        lineEdit->setText(QString());
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButtonDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Min", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Max", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Timing(s)", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButtonPut->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        pushButtonStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        labelStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
