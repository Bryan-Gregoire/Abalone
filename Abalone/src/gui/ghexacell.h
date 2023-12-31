#ifndef GHEXACELL_H
#define GHEXACELL_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include "model/Color.h"

/*
 * forward declaration.
 * put include in cpp file not in .h file
 */
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
 *
 * source : poc PBT and ABS.
 */
class GHexaCell : public QObject, public QGraphicsPolygonItem
{

    Q_OBJECT

  protected:
    double _x, _y; // coordinates of center
    const double _r; // radius
    std::string _value; // some value to emit (e.g. abapro position)
    abalone::Color _color; // Color of hexa
    bool _selected, mouseover, moved;


  public:
    /**
     * @brief GHexaCell constructor.
     * @param x x-abcis position.
     * @param y y-abcis position
     * @param r the radius.
     * @param color color of the cell.
     * @param value position of the cell.
     * @param parent parent of the cell.
     */
    explicit GHexaCell(double x, double y,
                       const double r,
                       abalone::Color color,
                       std::string value,
                       QGraphicsPolygonItem * parent = nullptr);

    /**
     * @brief x read accesor of the x position.
     * @return the x-abcis position of the cell.
     */
    inline double x() const;

    /**
     * @brief y read accesor of the y position.
     * @return the y-abcis position of the cell.
     */
    inline double y() const;

    /**
     * @brief r read accesor of the radius of the cell.
     * @return the radius of the cell.
     */
    inline double r() const;

    /**
     * @brief setSelect write accesor of the select which
     * represents if the box is selected.
     * @param selected represents whether to select the cell or not.
     */
    inline void setSelect(bool selected);

    /*
     * how can I what method rewrite ?
     * first because is in abs poc… and in doc
     * see https://doc.qt.io/qt-5/qgraphicspolygonitem.html#paint
     */
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

  protected:
    /*
     * Capture mouse press event. ghexacell is now clickable.
     * see https://www.learnqt.guide/events/working-with-events/
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * event);

    /*
     * #1 add signal to emit when hexagon is clicked.
     * this method must return void and is implemented by Qt.
     * To do this, class must inherit from QObject.
     */
  signals:
    void sendValue(std::string value, bool selected);
};

//
// inline methods
//
double GHexaCell::x() const
{
    return _x;
}

double GHexaCell::y() const
{
    return _y;
}

double GHexaCell::r() const
{
    return _r;
}

void GHexaCell::setSelect(bool selected) {
    _selected = selected;
}




#endif // GHEXACELL_H
