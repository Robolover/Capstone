/********************************************************************************
** Form generated from reading UI file 'rhythm_game.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RHYTHM_GAME_H
#define UI_RHYTHM_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rhythm_GameClass
{
public:
    QWidget *centralWidget;
    QPushButton *start_button;
    QLabel *camera;
    QPushButton *exit_button;
    QPushButton *music_image;
    QPushButton *upButtonBasic;
    QPushButton *downButtonBasic;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Rhythm_GameClass)
    {
        if (Rhythm_GameClass->objectName().isEmpty())
            Rhythm_GameClass->setObjectName(QStringLiteral("Rhythm_GameClass"));
        Rhythm_GameClass->resize(660, 500);
        centralWidget = new QWidget(Rhythm_GameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(30, 400, 275, 54));
        start_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/startButtonBasic.png);"));
        camera = new QLabel(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(10, 10, 640, 480));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(340, 400, 275, 54));
        exit_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/quitButtonBasic.png);"));
        music_image = new QPushButton(centralWidget);
        music_image->setObjectName(QStringLiteral("music_image"));
        music_image->setGeometry(QRect(570, 200, 61, 61));
        music_image->setStyleSheet(QStringLiteral("background-image: url(C:\\image/music_image_1.png);"));
        upButtonBasic = new QPushButton(centralWidget);
        upButtonBasic->setObjectName(QStringLiteral("upButtonBasic"));
        upButtonBasic->setGeometry(QRect(570, 20, 60, 60));
        upButtonBasic->setStyleSheet(QLatin1String("background-image: url(C:\\image/leftButtonBasic.png) 3 10 3 10;\n"
"border-top: 3px transparent;\n"
"border-bottom: 3px transparent; \n"
"border-right: 10px transparent;\n"
"border-left: 10px transparent;"));
        downButtonBasic = new QPushButton(centralWidget);
        downButtonBasic->setObjectName(QStringLiteral("downButtonBasic"));
        downButtonBasic->setGeometry(QRect(570, 400, 61, 61));
        downButtonBasic->setStyleSheet(QLatin1String("background-image: url(C:\\image/rightButtonBasic.png) 3 10 3 10;\n"
"border-top: 3px transparent;\n"
"border-bottom: 3px transparent; \n"
"border-right: 10px transparent;\n"
"border-left: 10px transparent;"));
        Rhythm_GameClass->setCentralWidget(centralWidget);
        camera->raise();
        exit_button->raise();
        start_button->raise();
        upButtonBasic->raise();
        downButtonBasic->raise();
        music_image->raise();
        mainToolBar = new QToolBar(Rhythm_GameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Rhythm_GameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Rhythm_GameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Rhythm_GameClass->setStatusBar(statusBar);

        retranslateUi(Rhythm_GameClass);
        QObject::connect(start_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(start_button()));
        QObject::connect(exit_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(exit_button()));
        QObject::connect(upButtonBasic, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_music()));
        QObject::connect(downButtonBasic, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_music()));
        QObject::connect(music_image, SIGNAL(clicked()), Rhythm_GameClass, SLOT(chose_music()));

        QMetaObject::connectSlotsByName(Rhythm_GameClass);
    } // setupUi

    void retranslateUi(QMainWindow *Rhythm_GameClass)
    {
        Rhythm_GameClass->setWindowTitle(QApplication::translate("Rhythm_GameClass", "Rhythm_Game", 0));
        start_button->setText(QString());
        camera->setText(QString());
        exit_button->setText(QString());
        music_image->setText(QString());
        upButtonBasic->setText(QString());
        downButtonBasic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rhythm_GameClass: public Ui_Rhythm_GameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RHYTHM_GAME_H
