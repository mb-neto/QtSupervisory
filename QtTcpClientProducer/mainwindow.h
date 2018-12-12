#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void putData();
  void tcpConnect();
  void tcpDisconnect();
  void start();
  void stop();
  void timerEvent(QTimerEvent *e);

  /**
   * @brief retorna um número inteiro que define o intervalo
   * entre dois números inteiros aleatórios
   * @param min é o limite inferior dos dados aleatórios desejados
   * @param max é o limite superior dos dados aleatórios desejados
   * @return true or false
   */
  int random(int min, int max);
  private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString ip;
  int timer;
};

#endif // MAINWINDOW_H
