#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();

  connect(ui->pushButtonConnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));

  connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));

  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(start()));

  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stop()));
}

void MainWindow::tcpConnect(){
  ip = ui->lineEdit->displayText();
  socket->connectToHost(ip,1234); // 127.0.0.1
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->status->setText("Connected\n");
  }
  else{
    qDebug() << "Disconnected";
    ui->status->setText("Disconnected\n");
  }
}

void MainWindow::tcpDisconnect(){
  socket->disconnectFromHost();
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->status->setText("Connected");
  }
  else{
    qDebug() << "Disconnected";
    ui->status->setText("Disconnected");
  }
}

int MainWindow::random(int min, int max){
    int x;

    if(min<max){
        x= qrand()%(max-min+1)+min;
    }
    else{
        x=0;
    }
    return x;
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str,s;
  qint64 msecdate;
  int min, max, x;

  min = ui->lcdNumberMin->value();
  max = ui->lcdNumberMax->value();

  x = random(min, max);

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + QString::number(x)+"\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
      ui->textBrowser->append(str);
  }
}

void MainWindow::timerEvent(QTimerEvent *e){
    putData();

    qDebug() << "Timer ID:" << e->timerId();
}

void MainWindow::start(){
  timer= startTimer(ui->horizontalSliderTiming->value()*10);
}

void MainWindow::stop(){
  killTimer(timer);
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}



