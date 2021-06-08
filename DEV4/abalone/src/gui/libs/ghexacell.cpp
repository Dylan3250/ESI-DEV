#include "ghexacell.h"

#include <cmath>

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

GHexaCell::GHexaCell(double x, double y, double r, std::string value,
                     std::optional<abalone::Ball> &ball,
                     QGraphicsPolygonItem *parent)
    : QGraphicsPolygonItem(parent),
      _x{x}, _y{y}, _r{r},
      _value{value},
      mouseover{false}, selected{false}, moved{false},
      _ball{ball} {
    this->setAcceptHoverEvents(true);
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

void GHexaCell::paint(QPainter *painter,
                      [[maybe_unused]] const QStyleOptionGraphicsItem *option,
[[maybe_unused]] QWidget *widget) {
    if (selected) {
        QBrush brush;
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    } else if (mouseover) {
        QBrush brush;
        brush.setColor(Qt::gray);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    } else {
        QPen pen(Qt::darkGray, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::lightGray);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());

    if (_ball) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        QPen pen(Qt::black, 1);

        if (_ball->color() == abalone::Color::BLACK) {
            brush.setColor(Qt::black);
        } else if (_ball->color() == abalone::Color::WHITE) {
            pen.setColor(Qt::white);
            brush.setColor(Qt::white);
        }

        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawEllipse(QPointF(0, 0), 30, 30);
    }
}

void GHexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    event->accept();
    mouseover = true;
    update();
}

void GHexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    event->accept();
    mouseover = false;
    update();
}

void GHexaCell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    moved = false;
    event->accept();
    selected = !selected;
    emit sendValue(_value);
    update();
}
