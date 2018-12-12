#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <plotter.h>
#include <vector>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tcpConnect();
    //Slots:
    //Inicia a transferencia de dados
    connect(ui->pushButtonGet,
            SIGNAL(clicked(bool)),
            this,
            SLOT(getData()));
    //Para a transferência de dados
    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopData()));
    //Conecta ao servidor
    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));
    //Desconecta do servidor
    connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));
    //Atualiza a lista de IPs
    connect(ui->pushButtonUpdate,
            SIGNAL(clicked(bool)),
            this,
            SLOT(ListHosts()));
}

QString MainWindow::getIP()
{
    QString ip;
    ip = ui->lineEditIpServer->displayText();
    qDebug() << ip;
    return ip;
}

void MainWindow::tcpConnect(){
    socket->connectToHost(getIP(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Server: Connected";
        ui->labelStatus->setText("Server: Connected");
    }
    else{
        qDebug() << "Server: Disconnected";
        ui->labelStatus->setText("Server: Disconnected");
    }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Server: Disconnected";
    ui->labelStatus->setText("Server: Disconnected");
}

void MainWindow::ListHosts()
{
    QString str,exception;
    QMessageBox raiseException;
    ui->listWidget->clear();
    if(socket->state() == QAbstractSocket::ConnectedState){
        socket->write("list\r\n");
        socket->waitForBytesWritten(3000);
        socket->waitForReadyRead(3000);
        if(socket->bytesAvailable() != 0 ){
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                ui->listWidget->addItem(str);
            }
        }else{
            exception = "HOST NÃO ENCONTRADO";
            raiseException.setText(exception);
            raiseException.exec();
        }
    }
    else{
        exception = "SERVIDOR NÃO CONECTADO";
        raiseException.setText(exception);
        raiseException.exec();
    }

}

void MainWindow::getData(){
    int timing;
    timing = ui->horizontalSlider->value();
    timerID= startTimer(timing*1000);
}

void MainWindow::stopData()
{
    killTimer(timerID);
}

//amostragem e normalização de dados
void MainWindow::timerEvent(QTimerEvent *event)
{
    QString str;
    QStringList list;
    qint64 thetime, num;
    std::vector<double> time;
    std::vector<double> data;
    std::vector<double> dado_standard;
    std::vector<double> tempo_standard;
    double Xmax, Ymax, Xmin, Ymin;

    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            str = "get " + ui->listWidget->currentItem()->text() + " 30\r\n";
            socket->write(str.toStdString().c_str());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            time.clear();
            data.clear();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");

                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    time.push_back(thetime);

                    str = list.at(1);
                    num = str.toLongLong(&ok);
                    data.push_back(num);
                    qDebug() << thetime << ": " << str;
                }
            }
        }
    }

    qDebug()<<data.size()<<time.size();
    //Detreminando os valores máximos e minimos para os tempos e os valores
    Xmax = time[0], Xmin = time[0];
    Ymin = data[0], Ymax = data[0];

    //Determinação do valor máximo é minimo para os tempos (algoritmo do trono)
    for(int i = 1 ; i < 30; i++){
        if(time[i] < Xmin){
            Xmin = time[i];
        }
        else if(time[i] > Xmax){
            Xmax = time[i];
        }
    }
    //Determinação do valor máximo é minimo para os valores/datas (algoritmo do trono)
    for(int i = 1 ; i < 30; i++){
        if(data[i] < Ymin){
            Ymin = data[i];
        }
        else if(data[i] > Ymax){
            Ymax = data[i];
        }
    }

    //normalizando dados
    tempo_standard.clear();
    dado_standard.clear();
    for(int i = 0; i<30; i++){
        dado_standard.push_back((data[i] - Ymin)/(Ymax -Ymin));
        tempo_standard.push_back((time[i] - Xmin)/(Xmax - Xmin));
    }
    ui->widget->loadData(tempo_standard,dado_standard);
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
