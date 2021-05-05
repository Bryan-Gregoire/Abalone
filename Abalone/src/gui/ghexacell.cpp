#include "ghexacell.h"

#include <cmath>

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

GHexaCell::GHexaCell(double x, double y,
                     const double r,
                     abalone::Color color,
                     std::string value,
                     QGraphicsPolygonItem * parent)
    : QGraphicsPolygonItem (parent),
      _x { x }, _y { y },
      _r {r},
      _value { value },
      _color {color}
{
    static const double pi_over_6 = atan(1) * 4 / 6;

    QPolygonF polygon;
    polygon << QPointF(r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(0, r);
    polygon << QPointF(-r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(-r * cos(pi_over_6), -r * sin(pi_over_6));
    polygon << QPointF(0, -r);
    polygon << QPointF(r * cos(pi_over_6), -r * sin(pi_over_6));
    setPolygon(polygon);
}


void GHexaCell::paint(QPainter * painter,
                      [[maybe_unused]] const QStyleOptionGraphicsItem * option,
[[maybe_unused]] QWidget * widget)
{
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    QBrush brush;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(polygon());
//    if(selected) {
//        QPen pen(Qt::blue, 5);
//        painter->setPen(pen);

//        QBrush brush;
//        brush.setColor(Qt::yellow);
//        brush.setStyle(Qt::SolidPattern);

//        painter->setBrush(brush);
//    }
//    else if(mouseover) {
//        QPen pen(Qt::blue, 1);
//        painter->setPen(pen);

//        QBrush brush;
//        brush.setColor(Qt::green);
//        brush.setStyle(Qt::SolidPattern);

//        painter->setBrush(brush);
//    }
//    else {
//        QPen pen(Qt::blue, 1);
//        painter->setPen(pen);

//        QBrush brush;
//        brush.setColor(Qt::cyan);
//        brush.setStyle(Qt::SolidPattern);

//        painter->setBrush(brush);
//    }

    if(_color == abalone::Color::BLACK) {

        brush.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
        painter->drawEllipse(-_r / 2 , -_r / 2, _r , _r);

    } else if(_color == abalone::Color::WHITE) {

        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
        painter->drawEllipse(-_r / 2 , -_r / 2, _r , _r);
    }
}


void GHexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    event->accept();
    qDebug() << "receive mouse event, emit signal";
    /*
     * #2 when componant is clicked, emit signal for who listen
     * (a slot elsewhere)
     */
    emit sendValue(_value);

}

