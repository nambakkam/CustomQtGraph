#ifndef AREACHART_H
#define AREACHART_H

#include <QtQuick/QQuickPaintedItem>
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
#include "randompointsgenerator.h"

class AreaChart : public QQuickPaintedItem
{
    Q_OBJECT
    QML_WRITABLE_VAR_PROPERTY(qreal, graphWidth)
    QML_WRITABLE_VAR_PROPERTY(qreal, graphHeight)
    QML_WRITABLE_VAR_PROPERTY(qreal,scale)



public:
    AreaChart(QQuickItem *parent = 0);

    void paint(QPainter *painter);

public slots:
    void drawGrid(QPainter *painter);
private:
    RandomPointsGenerator generator;
    void drawMinorGrid(QPainter *painter);
};

#endif // AREACHART_H
