#include "randompointsgenerator.h"
#include <QDateTime>
#include <QPointF>
#include <QtMath>

RandomPointsGenerator::RandomPointsGenerator(QObject *parent)
    : QObject{parent} {
  minValue = -500;
  maxValue = 500;
  time = 0;
  pointsTimer = new QTimer;
  pointsTimer->setInterval(20);
  QObject::connect(pointsTimer, &QTimer::timeout, this,
                   &RandomPointsGenerator::generateRandompoint);
  pointsTimer->start();
  switchTimer = new QTimer;
  switchTimer->setInterval(10000);
  QObject::connect(switchTimer, &QTimer::timeout, this, [this]() {
    this->minValue = (this->minValue == -500) ? -200 : -500;
    this->maxValue = (this->maxValue == 500) ? 200 : 500;
  });
  switchTimer->start();
}

void RandomPointsGenerator::generateRandompoint() {
  qreal y_value = getRand(minValue, maxValue);
  if (pointsY.size() <= 200) {
    time = time + 0.02;
    qreal x_value = time * 100;
    pointsX.append(x_value);
    pointsY.append(y_value);

  } else {
    pointsY.pop_front();
    pointsY.push_back(y_value);
  }
  emit pointsAdded();
}

qreal RandomPointsGenerator::getRand(int min, int max) {

  unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
  qreal value = min + (max - min) * qSin(ms);
  return value;
}

qreal RandomPointsGenerator::getMinX() const {
  if (pointsX.isEmpty())
    return std::numeric_limits<qreal>::min();
  return *std::min_element(pointsX.begin(), pointsX.end());
}

// Function to get the maximum value in pointsX
qreal RandomPointsGenerator::getMaxX() const {
  if (pointsX.isEmpty())
    return std::numeric_limits<qreal>::max();
  return *std::max_element(pointsX.begin(), pointsX.end());
}

// Function to get the minimum value in pointsY
qreal RandomPointsGenerator::getMinY() const {
  if (pointsY.isEmpty())
    return std::numeric_limits<qreal>::min();
  return *std::min_element(pointsY.begin(), pointsY.end());
}

// Function to get the maximum value in pointsY
qreal RandomPointsGenerator ::getMaxY() const {
  if (pointsY.isEmpty())
    return std::numeric_limits<qreal>::max();
  return *std::max_element(pointsY.begin(), pointsY.end());
}
