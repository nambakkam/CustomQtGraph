#include "areachart.h"
#include <QPainter>
#include <QPainterPath>
using namespace std;

AreaChart::AreaChart(QQuickItem *parent): QQuickPaintedItem(parent)
{
    QObject::connect(&generator,&RandomPointsGenerator::pointsAdded,[this]{
        QRect wholeRect;
        wholeRect.setRect(0,0,m_graphHeight,m_graphWidth);
        this->update(wholeRect);
    });
}



void AreaChart::paint(QPainter *painter)
{
    // Round the m_graphWidth and m_graphHeight to nearest 20 multiple
    m_graphHeight = static_cast<int>(m_graphHeight/20)*20;
    m_graphWidth =  static_cast<int>(m_graphWidth/20)*20;

    QLineF yAxis(0,0,0,m_graphHeight);
    QLineF xAxis(0,m_graphHeight,m_graphWidth,m_graphHeight);

    drawGrid(painter);
//    drawMinorGrid(painter);
    painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));
    painter->drawLine(yAxis);
    painter->drawLine(xAxis);


    for(int i=0; i < generator.points.size(); i++)
    {
        if(i>0){
        painter->setPen(QPen(QColor("red"), 2, Qt::SolidLine));
        painter->setBrush(QColor("transparent"));
        painter->drawLine((generator.points.at(i).x())/400*m_graphWidth,m_graphHeight-generator.points.at(i).y()/240*m_graphHeight,(generator.points.at(i-1).x())/400*m_graphWidth,m_graphHeight-generator.points.at(i-1).y()/240*m_graphHeight);
        }
//        painter->setPen(QPen(QColor("blue"), 7.5, Qt::SolidLine));
//        painter->setBrush(QColor("blue"));
//        qreal xScaled = (generator.points.at(i).x())/400*m_graphWidth;
//        qreal yScaled = m_graphHeight-generator.points.at(i).y()/240*m_graphHeight;
//        painter->drawPoint(QPointF(xScaled,yScaled));
    }
}
void AreaChart::drawGrid(QPainter *painter)
{
    QRectF gridRect;

    painter->setPen(QPen(QColor("lightgray"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));

    for(int i= 0; i < m_graphWidth; i += (m_graphWidth)/20)
    {
        for(int j=0; j< m_graphHeight; j += (m_graphHeight)/20){
            gridRect.setRect(i,j,m_graphWidth/20,m_graphHeight/20);
            painter->drawRect(gridRect);
        }
    }

}
void AreaChart::drawMinorGrid(QPainter *painter)
{
    QRectF gridRect;

    painter->setPen(QPen(QColor("lightgray"), 2, Qt::SolidLine));
    painter->setBrush(QColor("transparent"));

    for(int i= 0; i < m_graphWidth; i += (m_graphHeight+m_graphWidth)/100)
    {
        for(int j=0; j< m_graphHeight; j += (m_graphHeight+m_graphWidth)/100){
            qreal dimension = (m_graphHeight+m_graphWidth)/2;
            gridRect.setRect(i,j,dimension/50,dimension/50);
            painter->drawRect(gridRect);
        }
    }

}

