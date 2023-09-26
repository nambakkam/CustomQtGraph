#include "areachart.h"
#include <QPainter>
#include <QPainterPath>
using namespace std;

vector<int> xpos({0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195});
vector<int> ypos({140,150,140,170,160,160,170,190,220,140,150,150,190,170,160,180,160,150,170,180,140,150,130,170,140,150,170,190,180,160,150,150,190,150,170,180,160,150,170,200});

#define X_SHIFT  20
#define X_AXIS_YCOR 200

AreaChart::AreaChart(QQuickItem *parent): QQuickPaintedItem(parent)
{
    m_chdata = 0;
}

qreal AreaChart::chdata() const
{
    return m_chdata;
}

void AreaChart::setchdata(const qreal &chdata)
{
    if(chdata != m_chdata)
    {
        m_chdata = chdata;
        update();
        emit chdataChanged();
    }

}

void AreaChart::paint(QPainter *painter)
{
    std::rotate(ypos.begin(),ypos.begin()+1,ypos.end()-1); /*Rotating the plot points everytime when update() is called.*/

    QPainterPath areapath;

    /* Area chart path*/
    areapath.setFillRule(Qt::OddEvenFill);
    areapath.moveTo(X_SHIFT, X_AXIS_YCOR);	 /*Move to the bottom of the rectangle to start plotting. In qml, chart window is 200,200*/
    for(int i=0; i < xpos.size(); i++)
    {
        areapath.lineTo(xpos.at(i)+X_SHIFT,ypos.at(i));
    }

    /* Painting areachart path*/
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->setPen(QPen(QColor("pink"), 2, Qt::SolidLine,
                        Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(QColor("red"));
    painter->setOpacity(0.5);
    painter->drawPath(areapath);
}


