#include "gamemainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(on_exitButton_clicked()));
}
std::vector<Kaktus*> MainWindow::vect;
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_startButton_clicked()
{
    MainWindow::window.show();
    hide();
}
void MainWindow::on_exitButton_clicked()
{
    MainWindow::close();
}
