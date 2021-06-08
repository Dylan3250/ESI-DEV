#ifndef GHEXACELL_H
#define GHEXACELL_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include "game.h"

class QPainter;
class QPointF;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneMouseEvent;

/**
 * @brief The GHexaCell class.
 * represent an hexagon at position x,y and with a "value". this
 * value is emited on click.
 *
 * inherit from QObject to have capability of sending signal.
 */
class GHexaCell : public QObject, public QGraphicsPolygonItem {
    Q_OBJECT

protected:
    double _x, _y, _r;
    std::string _value;

public:
    /**
     * @brief Constructor of Hexagone Cell.
     * @param x point x of the center
     * @param y point y of the center
     * @param r radius of hexagon.
     * @param value value to emit
     * @param ball ball of the player
     * @param parent PolygonItem
     */
    explicit GHexaCell(double x, double y, double r, std::string value,
                       std::optional<abalone::Ball> &ball,
                       QGraphicsPolygonItem *parent = nullptr);

    /**
     * @brief Getter of x.
     * @return point x of the center.
     */
    inline double x() const;

    /**
     * @brief Getter of y.
     * @return point y of the the center.
     */
    inline double y() const;

    /**
     * @brief manages the visual of the shapes.
     * @param painter on widgets and other paint devices
     * @param option style option needed to draw
     * @param widget interface objects
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    bool mouseover, selected, moved;
    std::optional<abalone::Ball> _ball;

    /**
     * @brief Capture mouse press event.
     * @param event event captured
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief Capture hover enter event.
     * @param event event captured
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

    /**
     * @brief Capture leave event.
     * @param event event captured.
     */
     void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    /**
     * @brief Adds signal to emit when hexagon is clicked.
     * @param value is emited on click
     */
    void sendValue(std::string value);
};

/**
 * @brief  Getter of x.
 * @return point x of the center
 */
double GHexaCell::x() const {
    return _x;
}

/**
 * @brief Getter of y.
 * @return point y of the center
 */
double GHexaCell::y() const {
    return _y;
}

#endif // GHEXACELL_H
