#include "lineChart.h"
#include <QPainter>
#include <QPainterPath>
using namespace std;

Linechart::Linechart(QQuickPaintedItem *parent) : QQuickPaintedItem(parent) {
  QObject::connect(&generator, &RandomPointsGenerator::pointsAdded,
                   [this] { this->update(); });
}

void Linechart::paint(QPainter *painter) {

  // Round the width() and height() to nearest 20 multiple
  setWidth(static_cast<int>(width() / 200) * 200);
  setHeight(static_cast<int>(height() / 200) * 200);
  QLineF yAxis(0, 0, 0, height());
  QLineF xAxis(0, height(), width(), height());
  drawGrid(painter);
  painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
  painter->setBrush(QColor("transparent"));
  painter->drawLine(yAxis);
  painter->drawLine(xAxis);

  //  qreal xConst =
  //      generator.getMaxX() == 0 ? 1 / width() : generator.getMaxX() /
  //      width();
  qreal yBuff = 0.75;
  qreal xConst = 400 / width();
  qreal yConst =
      (generator.getMaxY() - generator.getMinY()) == 0
          ? 1 / (height())
          : (generator.getMaxY() - generator.getMinY()) / (height() * yBuff);

  for (int i = 0; i < generator.pointsY.size(); i++) {
    if (i > 0) {
      painter->setPen(QPen(QColor("red"), 2, Qt::SolidLine));
      painter->setBrush(QColor("transparent"));
      qreal xScaled = generator.pointsX.at(i) / xConst;
      qreal yScaled =
          height() * (1 - yBuff) / 2 +
          (generator.getMaxY() - generator.pointsY.at(i)) / (yConst);
      qreal xScaledPrev = generator.pointsX.at(i - 1) / xConst;
      qreal yScaledPrev =
          height() * (1 - yBuff) / 2 +
          (generator.getMaxY() - generator.pointsY.at(i - 1)) / (yConst);
      painter->drawLine(xScaled, yScaled, xScaledPrev, yScaledPrev);
    }
    painter->setPen(QPen(QColor("blue"), 7.5, Qt::SolidLine));
    painter->setBrush(QColor("blue"));
    qreal xScaled = (generator.pointsX.at(i)) / xConst;
    qreal yScaled = height() * (1 - yBuff) / 2 +
                    (generator.getMaxY() - generator.pointsY.at(i)) / (yConst);
    painter->drawPoint(QPointF(xScaled, yScaled));
  }
}
void Linechart::drawGrid(QPainter *painter) {
  QRectF gridRect;

  painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
  painter->setBrush(QColor("transparent"));
  set_gridWidth(width() / 20);
  set_gridHeight(height() / 20);
  for (int i = 0; i <= width(); i += m_gridWidth) {
    for (int j = 0; j <= height(); j += m_gridHeight) {
      gridRect.setRect(i, j, m_gridWidth, m_gridHeight);
      painter->drawRect(gridRect);
    }
  }
}
void Linechart::drawMinorGrid(QPainter *painter) {
  QRectF gridRect;

  painter->setPen(QPen(QColor("lightgray"), 2, Qt::SolidLine));
  painter->setBrush(QColor("transparent"));
  set_gridWidth(width() / 20);
  set_gridHeight(height() / 20);
  qreal dimension = (m_gridHeight + m_gridWidth) / 5;
  for (int i = 0; i <= width(); i += dimension) {
    for (int j = 0; j <= height(); j += dimension) {

      gridRect.setRect(i, j, dimension, dimension);
      painter->drawRect(gridRect);
    }
  }
}
