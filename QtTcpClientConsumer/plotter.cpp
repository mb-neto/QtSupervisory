#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    for(int i=0; i<30; i++){
        tempos.push_back(i);
        dados.push_back(i);
    }
}
void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    double x1, x2, y1, y2;

    // habilita o anti aliasing no intuito de deixar a figura mais "limpa"
    painter.setRenderHint(QPainter::Antialiasing);

    // brush com a cor amarela para preenchimento
    brush.setColor(QColor(255, 255, 100));
    brush.setStyle(Qt::SolidPattern);
    // informa ao painter qual o pincel atual
    painter.setBrush(brush);

    // pen com cor vermelha e dois pixels de largura
    pen.setColor(QColor(255,0,0));
    pen.setWidth(2);

    // informa ao painter qual o pen atual
    painter.setPen(pen);

    // desenha um retangulo tomando toda a area do slot
    painter.drawRect(0,0,width(), height());

    // pen com cor azul e dois pixels de largura
    pen.setColor(QColor(0,0,255));
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    // comunica ao painter a nova caneta
    painter.setPen(pen);


    //plotando o grafico do tempo(x) por dados(y)

    x1 = tempos[0]*width();
    y1 = dados[0]*(height()-dados[0]);

    for(int i=1; i<30; i++){
        x2=tempos[i]*width();
        y2=dados[i]*(height()-dados[i]);
        painter.drawLine(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }

}

void Plotter::loadData(std::vector<double> _tempos, std::vector<double> _dados)
{
    tempos=_tempos;
    dados=_dados;
    repaint();
}
