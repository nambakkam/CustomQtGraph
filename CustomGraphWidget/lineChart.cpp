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
  setAntialiasing(true);
  painter->setRenderHint(QPainter::Antialiasing, true);
  QLineF yAxis(0, 0, 0, height());
  QLineF xAxis(0, height(), width(), height());

  drawMinorGrid(painter);
  drawGrid(painter);
  painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
  painter->setBrush(QColor("transparent"));
  painter->drawLine(yAxis);
  painter->drawLine(xAxis);
  writeXandYticks(painter);

  for (int i = 0; i < generator.pointsY.size(); i++) {
    if (i > 0) {
      painter->setPen(QPen(QColor("red"), 2, Qt::SolidLine));
      painter->setBrush(QColor("transparent"));
      painter->drawLine((generator.pointsX.at(i)) / 400 * width(),
                        height() - generator.pointsY.at(i) / 240 * height(),
                        (generator.pointsX.at(i - 1)) / 400 * width(),
                        height() -
                            generator.pointsY.at(i - 1) / 240 * height());
    }
    painter->setPen(QPen(QColor("blue"), 7.5, Qt::SolidLine));
    painter->setBrush(QColor("blue"));
    qreal xScaled = (generator.pointsX.at(i)) / 400 * width();
    qreal yScaled = height() - generator.pointsY.at(i) / 240 * height();
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
void Linechart::writeXandYticks(QPainter *painter) {
  QFont textFont;
  textFont.setPixelSize(0.02 * width());
  textFont.setFamily("ROBOTO");
  textFont.setStyleName("Medium");

  painter->setPen(QPen(QColor("black"), 2, Qt::SolidLine));
  painter->setBrush(QColor("black"));
  painter->setFont(textFont);

  for (int i = 0; i <= width(); i += width() / 20) {
    m_xTicks.append(i);
    painter->drawText(QPointF(i, 1.1 * height()), QString::number(i));
  }
  for (int j = 0; j <= height(); j += height() / 20) {
    painter->drawText(QPointF(-0.1 * width(), height() - j),
                      QString::number(j));
    m_yTicks.append(j);
  }
}
