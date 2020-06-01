#include "mainwindow.h"
#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"
#include<iostream>
#include<thread>
#include<QThread>
#include <random>
#include <qmessagebox.h>
class Sleeper: public QThread
{
    public:
        static void msleep(int ms)
        {
            QThread::msleep(ms);
        }
};
void GameMainWindow::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Space)
    {
        emit spacePressed(); // connected elsewhere

    }
}
GameMainWindow::GameMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameMainWindow)
{
    initialyze();
}

GameMainWindow::~GameMainWindow()
{
    delete ui;
}
void GameMainWindow::slotGameTimer(){
    std::cout << "start";
    dinoItem->setPos(-100,-83);
    //qApp->processEvents();
    //TODO вывести объявление таймера и лупа и connect в конструктор
    jumpTimer.start();
    jumpLoop.exec();
    dinoItem->setPos(-100,-33);
    //qApp->processEvents();
}
void GameMainWindow::generateNew()
{
    int result = 1 + (rand() % 3);
    int result1 = 500 + (rand() % 500);
    kaktus = new Kaktus(result, result1, scene, kaktusItem1, kaktusItem2, kaktusItem3);
    qApp->processEvents();
}
void GameMainWindow::initialyze()
{
    triangle = new Triangle();      /// Initialize triangle
    //home/albert/C++/CrazyPig/dino.png
    triangle->dino.load(":/dino/superminidino.png");
    triangle->kaktus.load(":/dino/miniKaktus.png");
    dinoItem = new QGraphicsPixmapItem(QPixmap::fromImage(triangle->dino));
    kaktusItem1 = new QGraphicsPixmapItem(QPixmap::fromImage(triangle->kaktus));
    kaktusItem2 = new QGraphicsPixmapItem(QPixmap::fromImage(triangle->kaktus));
    kaktusItem3 = new QGraphicsPixmapItem(QPixmap::fromImage(triangle->kaktus));
    ui->setupUi(this);
    this->resize(600,600);          /// Defining the size of the widget, ie the window
    this->setFixedSize(600,600);    /// Fix a widget sizes
    scene = new QGraphicsScene();   /// Initialize the graphics scene
    ui->graphicsView->setScene(scene);  /// Set the graphic scene in qgraphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Install anti-aliasing
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Disable scroll vertically
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Disable scroll horizontally
    scene->setSceneRect(-250,-250,500,500); /// Set the graphic scenes
    scene->addLine(-300,0,300,0,QPen(Qt::black));   /// Adding a horizontal line through the center
    scene->addItem(dinoItem);
    srand(time(0));
    dinoItem->setPos(-100, -33);
    generateNew();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000 / 250);
    qApp->processEvents();
    connect(this, SIGNAL(spacePressed()), this, SLOT(slotGameTimer()));
    jumpTimer.setInterval(700); //5 sec
    connect (&jumpTimer, SIGNAL(timeout()), &jumpLoop, SLOT(quit()));
}
void GameMainWindow::gameOver()
{
    if (QMessageBox::Yes == QMessageBox::information(NULL,
                            tr("Game Over"), tr("Try again?"),
                            QMessageBox::Yes | QMessageBox::No,
                            QMessageBox::Yes)) {
        kaktus->remove();
        generateNew();
    } else {
        exit(0);
    }
}
