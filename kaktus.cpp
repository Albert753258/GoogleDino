#include "kaktus.h"
#include "gamemainwindow.h"
#include"mainwindow.h"
#include<iostream>
#include<QApplication>
Kaktus::Kaktus(int count, int dest, QGraphicsScene  *scene, QGraphicsPixmapItem *kaktusItem1, QGraphicsPixmapItem *kaktusItem2, QGraphicsPixmapItem *kaktusItem3)
{
    this->kaktusItem1 = kaktusItem1;
    this->kaktusItem2 = kaktusItem2;
    this->kaktusItem3 = kaktusItem3;
    this->dest = dest;
    this->count = count;
    this->scene = scene;
    if(count == 1)
    {
        scene->addItem(kaktusItem1);
        kaktusItem1->setPos(dest, -39);
    }
    else if(count == 2)
    {
        scene->addItem(kaktusItem1);
        kaktusItem1->setPos(dest, -39);
        scene->addItem(kaktusItem2);
        kaktusItem2->setPos(dest + 17, -39);
    }
    else
    {
        scene->addItem(kaktusItem1);
        kaktusItem1->setPos(dest, -39);
        scene->addItem(kaktusItem2);
        kaktusItem2->setPos(dest + 17, -39);
        scene->addItem(kaktusItem3);
        kaktusItem3->setPos(dest + 34, -39);
    }
    MainWindow::vect.push_back(this);
}
void Kaktus::remove()
{
    if(count == 1)
    {
        scene->removeItem(kaktusItem1);
    }
    else if(count == 2)
    {
        scene->removeItem(kaktusItem1);
        scene->removeItem(kaktusItem2);
    }
    else
    {
        scene->removeItem(kaktusItem1);
        scene->removeItem(kaktusItem2);
        scene->removeItem(kaktusItem3);
    }
}
void Kaktus::setX(int x)
{
    if(count == 1)
    {
        kaktusItem1->setPos(x, -39);
    }
    else if(count == 2)
    {
        kaktusItem1->setPos(x, -39);
        kaktusItem2->setPos(x + 17, -39);
    }
    else
    {
        kaktusItem1->setPos(x, -39);
        kaktusItem2->setPos(x + 17, -39);
        kaktusItem3->setPos(x + 34, -39);
    }
}
int Kaktus::x()
{
    return kaktusItem1->x();
}
void GameMainWindow::move()
{
    kaktus->setX(kaktus->x() - 1);
    bool godMod = false;
    if(!godMod)
    {
        if((dinoItem->y() == -33) && ((dinoItem->x() + 31 >= kaktus->x())) && (dinoItem->x() <= kaktus->x() + 17 * kaktus->count))
        {
            gameOver();
        }
//        if((dinoItem->y() == -33) && ((dinoItem->x() + 31 >= kaktus->x()) && (dinoItem->x() <= kaktus->x() + 31 * kaktus->count)))
//        {
//            std::cout << dinoItem->y() << std::endl;
//            std::cout << dinoItem->x() << std::endl;
//            gameOver();
//        }
    }
    if(kaktus->x() < -350)
    {
        kaktus->remove();
        generateNew();
    }
    //qApp->processEvents();
}
