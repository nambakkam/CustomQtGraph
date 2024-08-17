#ifndef LINECHART_H
#define LINECHART_H

#include "randompointsgenerator.h"
#include <QObject>
#include <QQmlVarPropertyHelpers.h>
#include <QVector>
#include <QtQuick/QQuickPaintedItem>

class Linechart : public QQuickPaintedItem {
  Q_OBJECT
  QML_WRITABLE_VAR_PROPERTY(QVector<qreal>, xTicks)
  QML_WRITABLE_VAR_PROPERTY(QVector<qreal>, yTicks)
  QML_WRITABLE_VAR_PROPERTY(qreal, gridWidth)
  QML_WRITABLE_VAR_PROPERTY(qreal, gridHeight)
public:
  Linechart(QQuickPaintedItem *parent = 0);

  void paint(QPainter *painter) override;

public slots:

private:
  RandomPointsGenerator generator;
  void drawMinorGrid(QPainter *painter);
  void drawGrid(QPainter *painter);
  qreal xOffset;
  qreal yOffset;
};

#endif // LINECHART_H
