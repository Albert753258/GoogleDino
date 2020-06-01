#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gamemainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_startButton_clicked();
    void on_exitButton_clicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    GameMainWindow window;
    static std::vector<Kaktus*> vect;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
