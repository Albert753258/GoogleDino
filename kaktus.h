#ifndef KAKTUSMOVER_H
#define KAKTUSMOVER_H
#include <QGraphicsScene>
#include<QWidget>
//#include"mainwindow.h"

class Kaktus: public QObject
{
public slots:
    void move();
public:
    Kaktus(int count, int dest, QGraphicsScene  *scene, QGraphicsPixmapItem *kaktusItem1, QGraphicsPixmapItem *kaktusItem2, QGraphicsPixmapItem *kaktusItem3);
    void setX(int x);
    int x();
    QGraphicsPixmapItem *kaktusItem1;
    QGraphicsPixmapItem *kaktusItem2;
    QGraphicsScene  *scene;
    int count;
    void remove();
    int dest;
    QGraphicsPixmapItem *kaktusItem3;
};

#endif // KAKTUSMOVER_H
