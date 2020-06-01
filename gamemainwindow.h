#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include<QKeyEvent>
#include <QEventLoop>
#include"kaktus.h"
#include <triangle.h>
#include<vector>

namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameMainWindow(QWidget *parent = 0);
    ~GameMainWindow();
    void keyPressEvent(QKeyEvent *event);
    void moveDino();
signals:
    void spacePressed();
public slots:
    void slotGameTimer();
    void move();

public:
    Ui::GameMainWindow      *ui;
    QGraphicsScene  *scene;     /// We declare a graphic scene
    Triangle        *triangle;  /// and triangle
    QTimer          *timer;     /* We declare the game a timer,
                                 * by which will be changing the position of an object
                                 * on the stage when exposed to the keyboard keys
                                 * */
    QGraphicsPixmapItem *dinoItem;
    QGraphicsPixmapItem *kaktusItem1;
    QGraphicsPixmapItem *kaktusItem2;
    void generateNew();
    void initialyze();
    void gameOver();
    QEventLoop jumpLoop;
    QTimer jumpTimer;
    QGraphicsPixmapItem *kaktusItem3;
    void myUpdate();
    //static GameMainWindow *window;
    Kaktus *kaktus;
};

#endif // WIDGET_H
