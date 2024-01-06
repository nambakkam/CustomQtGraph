#ifndef RANDOMPOINTSGENERATOR_H
#define RANDOMPOINTSGENERATOR_H

#include <QObject>
#include <QQmlListPropertyHelper.h>
#include <QVector>
#include <QTimer>
#include <QPointF>

class RandomPointsGenerator : public QObject
{
    Q_OBJECT

public:
    explicit RandomPointsGenerator(QObject *parent = nullptr);
    QVector<QPointF> points;

public slots:
    void generateRandompoint();

private:
    QTimer* pointsTimer;
    qreal getRand(int min, int max);
    qreal time;

signals:
    void pointsAdded();
};

#endif // RANDOMPOINTSGENERATOR_H
