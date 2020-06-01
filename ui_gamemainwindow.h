/********************************************************************************
** Form generated from reading UI file 'gamemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMAINWINDOW_H
#define UI_GAMEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMainWindow
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GameMainWindow)
    {
        if (GameMainWindow->objectName().isEmpty())
            GameMainWindow->setObjectName(QString::fromUtf8("GameMainWindow"));
        GameMainWindow->resize(400, 300);
        gridLayout = new QGridLayout(GameMainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(GameMainWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(GameMainWindow);

        QMetaObject::connectSlotsByName(GameMainWindow);
    } // setupUi

    void retranslateUi(QWidget *GameMainWindow)
    {
        GameMainWindow->setWindowTitle(QCoreApplication::translate("GameMainWindow", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMainWindow: public Ui_GameMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMAINWINDOW_H
