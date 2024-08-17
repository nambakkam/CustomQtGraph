#ifndef RANDOMPOINTSGENERATOR_H
#define RANDOMPOINTSGENERATOR_H

#include <QObject>
#include <QPointF>
#include <QQmlListPropertyHelper.h>
#include <QTimer>
#include <QVector>

class RandomPointsGenerator : public QObject {
  Q_OBJECT

public:
  explicit RandomPointsGenerator(QObject *parent = nullptr);
  QVector<qreal> pointsX;
  QVector<qreal> pointsY;

  qreal getMinX() const;
  qreal getMaxX() const;
  qreal getMinY() const;
  qreal getMaxY() const;
public slots:
  void generateRandompoint();

private:
  QTimer *pointsTimer;
  QTimer *switchTimer;
  qreal getRand(int min, int max);

  qreal time;
  int minValue, maxValue;

signals:
  void pointsAdded();
};

#endif // RANDOMPOINTSGENERATOR_H
