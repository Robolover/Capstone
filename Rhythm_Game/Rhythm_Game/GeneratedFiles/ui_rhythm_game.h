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
#include <QtWidgets/QGraphicsView>
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
    QPushButton *stage_1;
    QPushButton *left_button;
    QPushButton *right_button;
    QPushButton *stage_2;
    QPushButton *stage_3;
    QGraphicsView *video;
    QPushButton *main_button;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Rhythm_GameClass)
    {
        if (Rhythm_GameClass->objectName().isEmpty())
            Rhythm_GameClass->setObjectName(QStringLiteral("Rhythm_GameClass"));
        Rhythm_GameClass->resize(670, 500);
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
        stage_1 = new QPushButton(centralWidget);
        stage_1->setObjectName(QStringLiteral("stage_1"));
        stage_1->setGeometry(QRect(130, 340, 120, 120));
        stage_1->setStyleSheet(QStringLiteral("background-image: url(C:\\image/music_image_1.png);"));
        left_button = new QPushButton(centralWidget);
        left_button->setObjectName(QStringLiteral("left_button"));
        left_button->setGeometry(QRect(20, 400, 60, 60));
        left_button->setStyleSheet(QLatin1String("background-image: url(C:\\image/leftButtonBasic.png) 3 10 3 10;\n"
"border-top: 3px transparent;\n"
"border-bottom: 3px transparent; \n"
"border-right: 10px transparent;\n"
"border-left: 10px transparent;"));
        right_button = new QPushButton(centralWidget);
        right_button->setObjectName(QStringLiteral("right_button"));
        right_button->setGeometry(QRect(570, 400, 60, 60));
        right_button->setStyleSheet(QLatin1String("background-image: url(C:\\image/rightButtonBasic.png) 3 10 3 10;\n"
"border-top: 3px transparent;\n"
"border-bottom: 3px transparent; \n"
"border-right: 10px transparent;\n"
"border-left: 10px transparent;"));
        stage_2 = new QPushButton(centralWidget);
        stage_2->setObjectName(QStringLiteral("stage_2"));
        stage_2->setGeometry(QRect(300, 400, 60, 60));
        stage_2->setStyleSheet(QStringLiteral("background-image: url(C:\\image/music_image_2.png);"));
        stage_3 = new QPushButton(centralWidget);
        stage_3->setObjectName(QStringLiteral("stage_3"));
        stage_3->setGeometry(QRect(430, 400, 60, 60));
        stage_3->setStyleSheet(QStringLiteral("background-image: url(C:\\image/music_image_3.png);"));
        video = new QGraphicsView(centralWidget);
        video->setObjectName(QStringLiteral("video"));
        video->setGeometry(QRect(10, 10, 640, 480));
        main_button = new QPushButton(centralWidget);
        main_button->setObjectName(QStringLiteral("main_button"));
        main_button->setGeometry(QRect(180, 380, 341, 80));
        main_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/great.png);"));
        Rhythm_GameClass->setCentralWidget(centralWidget);
        camera->raise();
        video->raise();
        right_button->raise();
        stage_1->raise();
        stage_2->raise();
        stage_3->raise();
        left_button->raise();
        main_button->raise();
        exit_button->raise();
        start_button->raise();
        mainToolBar = new QToolBar(Rhythm_GameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Rhythm_GameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Rhythm_GameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Rhythm_GameClass->setStatusBar(statusBar);

        retranslateUi(Rhythm_GameClass);
        QObject::connect(start_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(start_button()));
        QObject::connect(exit_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(exit_button()));
        QObject::connect(right_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_next_stage()));
        QObject::connect(stage_2, SIGNAL(clicked()), Rhythm_GameClass, SLOT(chose_stage()));
        QObject::connect(stage_1, SIGNAL(clicked()), Rhythm_GameClass, SLOT(chose_stage()));
        QObject::connect(right_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(play_game()));
        QObject::connect(stage_3, SIGNAL(clicked()), Rhythm_GameClass, SLOT(chose_stage()));
        QObject::connect(left_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_before_stage()));
        QObject::connect(main_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(return_main()));
        QObject::connect(right_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(next_stage()));

        QMetaObject::connectSlotsByName(Rhythm_GameClass);
    } // setupUi

    void retranslateUi(QMainWindow *Rhythm_GameClass)
    {
        Rhythm_GameClass->setWindowTitle(QApplication::translate("Rhythm_GameClass", "Rhythm_Game", 0));
        start_button->setText(QString());
        camera->setText(QString());
        exit_button->setText(QString());
        stage_1->setText(QString());
        left_button->setText(QString());
        right_button->setText(QString());
        stage_2->setText(QString());
        stage_3->setText(QString());
        main_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rhythm_GameClass: public Ui_Rhythm_GameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RHYTHM_GAME_H
