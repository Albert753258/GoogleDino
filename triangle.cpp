#include "triangle.h"
#include"chrono"
#include"thread"
#include"time.h"
#include"iostream"

Triangle::Triangle(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    //dino.load("images/dino");
    QGraphicsPixmapItem item( QPixmap::fromImage(dino));
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(&item);
    angle = 0;
    setRotation(angle);
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   //

        polygon << QPoint(25,-25) << QPoint(25,25) << QPoint(-25,25)  << QPoint(-25,-25);
        painter->setBrush(Qt::red);
        painter->drawPolygon(polygon);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Triangle::up()
{
//    std::cout << "X" << this->x() << std::endl;
//    std::cout << "Y" << this->y() << std::endl;
    /* Alternately checks for key presses
     * using the asynchronous reception state of the keys
     * is provided WinAPI
     * */
//    setPos(mapToParent(0, 5));
//    if(GetAsyncKeyState(VK_SPACE)){
//        setPos(mapToParent(0, 5));      /* Move the object 5 pixels backward to retranslate them
//                                         * in the coordinate system of the graphic scene
//                                         * */
//        //using namespace std::this_thread; // sleep_for, sleep_until
//        //using namespace std::chrono; // nanoseconds, system_clock, seconds
//        //sleep_for(milliseconds(300));
//        //sleep_until(system_clock::now() + seconds(1));
//        setPos(mapToParent(0, -5));
//    }

//    /* Check output of bounds. If the subject is beyond the set boundaries, then return it back
//     * */
//    if(this->x() - 10 < -250){
//        this->setX(-240);       // left
//    }
//    if(this->x() + 10 > 250){
//        this->setX(240);        // right
//    }

//    if(this->y() - 10 < -250){
//        this->setY(-240);       // top
//    }
//    if(this->y() + 10 > 250){
//        this->setY(240);        // bottom
//    }
    //if(GetAsyncKeyState(VK_SPACE)){
             /* Move the object 5 pixels forward to retranslate them
                                         * in the coordinate system of the graphic scene
                                         * */
    setPos(mapToParent(0, -50));
}
void Triangle::down()
{
    setPos(mapToParent(0, 50));
}
