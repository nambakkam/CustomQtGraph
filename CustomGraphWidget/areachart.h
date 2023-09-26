#ifndef AREACHART_H
#define AREACHART_H

#include <QtQuick/QQuickPaintedItem>
#include <QObject>

class AreaChart : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal chdata READ chdata WRITE setchdata NOTIFY chdataChanged)

public:
    AreaChart(QQuickItem *parent = 0);

    qreal chdata() const;
    void setchdata(const qreal &chdata);

    void paint(QPainter *painter);
signals:
    void chdataChanged();
private:
    qreal m_chdata;
};

#endif // AREACHART_H
