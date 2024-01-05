#include "randompointsgenerator.h"
#include <QPointF>
#include <QDateTime>
#include <QtMath>

RandomPointsGenerator::RandomPointsGenerator(QObject *parent)
    : QObject{parent}
{
    time = 0;
    pointsTimer = new QTimer;
    pointsTimer->setInterval(20);
    QObject::connect(pointsTimer,&QTimer::timeout,this,&RandomPointsGenerator::generateRandompoint);
    pointsTimer->start();
}

void RandomPointsGenerator::generateRandompoint(){
    if(points.size()<=100){
        time = time + 0.02;
        qreal x_value = time*100;
        qreal y_value = getRand(0,230);

        points.append(QPointF(x_value,y_value));

    }
    else{
        qreal x_value = time*100;
        qreal y_value = getRand(0,230);
        points.pop_front();
        points.push_back(QPointF(x_value,y_value));
    }
    emit pointsAdded();

}

qreal RandomPointsGenerator::getRand(int min, int max){

    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    qreal value = min+(max-min)*qSin(ms);
    return value;
}
