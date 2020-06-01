#ifndef MOVEDINO_H
#define MOVEDINO_H


#include <QThread>

class MoveDino : public QThread
{
public:
    explicit MoveDino(QString threadName);

    // Переопределяем метод run(), в котором будет
    // располагаться выполняемый код
    void run();
private:
    QString name;   // Имя потока
};

#endif // MOVEDINO_H
