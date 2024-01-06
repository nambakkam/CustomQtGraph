#include "lineChart.h"
#include <QPainter>
#include <QPainterPath>
using namespace std;

Linechart::Linechart(QQuickPaintedItem *parent): QQuickPaintedItem(parent)
{
    QObject::connect(&generator,&RandomPointsGenerator::pointsAdded,[this]
    {
        this->update();
    });
}



void Linechart::paint(QPainter *painter)
{

    // Round the width() and height() to nearest 20 multiple

    setWidth(static_cast<int>(width()/20)*20);
    setHeight(static_cast<int>(height()/20)*20);
    setAntialiasing(true);
    painter->setRenderHint(QPainter::Antialiasing);
    QLineF yAxis(0,0,0,height());
    QLineF xAxis(0,height(),width(),height());

    drawGrid(painter);
//    drawMinorGrid(painter);
    painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));
    painter->drawLine(yAxis);
    painter->drawLine(xAxis);
    writeXandYticks(painter);

    for(int i=0; i < generator.points.size(); i++)
    {
        if(i>0){
        painter->setPen(QPen(QColor("red"), 2, Qt::SolidLine));
        painter->setBrush(QColor("transparent"));
        painter->drawLine((generator.points.at(i).x())/400*width(),height()-generator.points.at(i).y()/240*height(),(generator.points.at(i-1).x())/400*width(),height()-generator.points.at(i-1).y()/240*height());
        }
        painter->setPen(QPen(QColor("blue"), 7.5, Qt::SolidLine));
        painter->setBrush(QColor("blue"));
        qreal xScaled = (generator.points.at(i).x())/400*width();
        qreal yScaled = height()-generator.points.at(i).y()/240*height();
        painter->drawPoint(QPointF(xScaled,yScaled));
    }
}
void Linechart::drawGrid(QPainter *painter)
{
    QRectF gridRect;

    painter->setPen(QPen(QColor("lightgray"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));

    for(int i= 0; i <= width(); i += (width())/20)
    {
        for(int j=0; j<= height(); j += (height())/20){
            gridRect.setRect(i,j,width()/20,height()/20);
            painter->drawRect(gridRect);
        }
    }

}
void Linechart::drawMinorGrid(QPainter *painter)
{
    QRectF gridRect;

    painter->setPen(QPen(QColor("lightgray"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));

    for(int i= 0; i < width(); i += (height()+width())/100)
    {
        for(int j=0; j< height(); j += (height()+width())/100){
            qreal dimension = (height()+width())/2;
            gridRect.setRect(i,j,dimension/50,dimension/50);
            painter->drawRect(gridRect);
        }
    }

}
void Linechart::writeXandYticks(QPainter *painter){
    QFont textFont;
    textFont.setPixelSize(0.02*width());
    textFont.setFamily("ROBOTO");
    textFont.setStyleName("Medium");

    painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));
    painter->setFont(textFont);

    for(int i= 0; i <= width(); i += width()/20)
    {
        painter->drawText(QPointF(i,1.1*height()),QString::number(i));
    }
    for(int j= 0; j <= height(); j += height()/20)
    {
        painter->drawText(QPointF(-0.1*width(),height()-j),QString::number(j));
    }
}

