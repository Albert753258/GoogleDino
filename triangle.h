#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

/* Connect the library is responsible for the use WinAPI.
 * This library is required to check the status of asynchronous keys
 * */

class Triangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Triangle(QObject *parent = 0);
    ~Triangle();

signals:

public:
    void up();
    void down();
    QImage dino;
    QImage kaktus;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;    // The angle of rotation of the graphic object
};

#endif // TRIANGLE_H
