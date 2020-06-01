#include "movedino.h"
#include"gamemainwindow.h"
#include <QDebug>

MoveDino::MoveDino(QString threadName) :
    name(threadName)
{

}

void MoveDino::run()
{
    std::cout << "start";
    GameMainWindow::dinoItem->setPos(-100,-133);
    qApp->processEvents();
    time_t timesddsfedwf;
    timesddsfedwf = time(NULL);
    int timeint = (int)timesddsfedwf;
    //std::cout << (int)timesddsfedwf << std::endl;
    int temp = (int)timesddsfedwf - timeint;
    while(temp < 2)
    {
        timesddsfedwf = time(NULL);
        temp = (int)timesddsfedwf - timeint;
        //std::cout << temp << std::endl;
    }
    dinoItem->setPos(-100,-33);
    qApp->processEvents();
}
