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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rhythm_GameClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stacked_widget;
    QWidget *intro_widget;
    QGraphicsView *intro_video;
    QLabel *label;
    QWidget *main_widget;
    QPushButton *start_button;
    QPushButton *quit_button;
    QLabel *camera;
    QWidget *stage_widget;
    QPushButton *left_button;
    QPushButton *right_button;
    QPushButton *stage_1;
    QPushButton *stage_2;
    QPushButton *stage_3;
    QLabel *camera_2;
    QWidget *video_widget;
    QGraphicsView *video;
    QPushButton *next_button;
    QWidget *play_widget;
    QPushButton *apple;
    QPushButton *bus;
    QPushButton *cat;
    QPushButton *duck;
    QLabel *camera_3;
    QWidget *result_widget;
    QLabel *great;
    QLabel *fail;
    QPushButton *return_main;
    QPushButton *quit_button_2;
    QLabel *camera_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Rhythm_GameClass)
    {
        if (Rhythm_GameClass->objectName().isEmpty())
            Rhythm_GameClass->setObjectName(QStringLiteral("Rhythm_GameClass"));
        Rhythm_GameClass->resize(1300, 750);
        centralWidget = new QWidget(Rhythm_GameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stacked_widget = new QStackedWidget(centralWidget);
        stacked_widget->setObjectName(QStringLiteral("stacked_widget"));
        stacked_widget->setGeometry(QRect(0, 12, 1280, 720));
        intro_widget = new QWidget();
        intro_widget->setObjectName(QStringLiteral("intro_widget"));
        intro_video = new QGraphicsView(intro_widget);
        intro_video->setObjectName(QStringLiteral("intro_video"));
        intro_video->setGeometry(QRect(0, 12, 1280, 720));
        label = new QLabel(intro_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 12, 1280, 720));
        stacked_widget->addWidget(intro_widget);
        main_widget = new QWidget();
        main_widget->setObjectName(QStringLiteral("main_widget"));
        start_button = new QPushButton(main_widget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(50, 600, 400, 80));
        start_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/startButtonBasic.png);"));
        quit_button = new QPushButton(main_widget);
        quit_button->setObjectName(QStringLiteral("quit_button"));
        quit_button->setGeometry(QRect(850, 600, 400, 80));
        quit_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/quitButtonBasic.png);"));
        camera = new QLabel(main_widget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(0, 12, 1280, 720));
        stacked_widget->addWidget(main_widget);
        camera->raise();
        start_button->raise();
        quit_button->raise();
        stage_widget = new QWidget();
        stage_widget->setObjectName(QStringLiteral("stage_widget"));
        left_button = new QPushButton(stage_widget);
        left_button->setObjectName(QStringLiteral("left_button"));
        left_button->setGeometry(QRect(50, 280, 151, 400));
        left_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/leftButtonBasic.png);"));
        right_button = new QPushButton(stage_widget);
        right_button->setObjectName(QStringLiteral("right_button"));
        right_button->setGeometry(QRect(1090, 280, 150, 400));
        right_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/rightButtonBasic.png);"));
        stage_1 = new QPushButton(stage_widget);
        stage_1->setObjectName(QStringLiteral("stage_1"));
        stage_1->setGeometry(QRect(520, 350, 300, 250));
        stage_1->setStyleSheet(QStringLiteral("background-image: url(C:\\image/stage1.png);"));
        stage_2 = new QPushButton(stage_widget);
        stage_2->setObjectName(QStringLiteral("stage_2"));
        stage_2->setGeometry(QRect(520, 350, 300, 250));
        stage_2->setStyleSheet(QStringLiteral("background-image: url(C:\\image/stage2.png);"));
        stage_3 = new QPushButton(stage_widget);
        stage_3->setObjectName(QStringLiteral("stage_3"));
        stage_3->setGeometry(QRect(520, 350, 300, 250));
        stage_3->setStyleSheet(QStringLiteral("background-image: url(C:\\image/stage3.png);"));
        camera_2 = new QLabel(stage_widget);
        camera_2->setObjectName(QStringLiteral("camera_2"));
        camera_2->setGeometry(QRect(0, 12, 1280, 720));
        stacked_widget->addWidget(stage_widget);
        camera_2->raise();
        left_button->raise();
        right_button->raise();
        stage_2->raise();
        stage_3->raise();
        stage_1->raise();
        video_widget = new QWidget();
        video_widget->setObjectName(QStringLiteral("video_widget"));
        video = new QGraphicsView(video_widget);
        video->setObjectName(QStringLiteral("video"));
        video->setGeometry(QRect(0, 12, 1280, 720));
        next_button = new QPushButton(video_widget);
        next_button->setObjectName(QStringLiteral("next_button"));
        next_button->setGeometry(QRect(1170, 620, 60, 60));
        next_button->setStyleSheet(QStringLiteral("background-image: url(C:\\image/next_button.png);"));
        stacked_widget->addWidget(video_widget);
        play_widget = new QWidget();
        play_widget->setObjectName(QStringLiteral("play_widget"));
        apple = new QPushButton(play_widget);
        apple->setObjectName(QStringLiteral("apple"));
        apple->setGeometry(QRect(1020, 420, 200, 200));
        apple->setStyleSheet(QStringLiteral("background-image : url(C:\\image/apple.png)"));
        bus = new QPushButton(play_widget);
        bus->setObjectName(QStringLiteral("bus"));
        bus->setGeometry(QRect(330, 120, 200, 200));
        bus->setStyleSheet(QStringLiteral("background-image : url(C:\\image/bus.png)"));
        cat = new QPushButton(play_widget);
        cat->setObjectName(QStringLiteral("cat"));
        cat->setGeometry(QRect(730, 120, 200, 200));
        cat->setStyleSheet(QStringLiteral("background-image : url(C:\\image/cat.png)"));
        duck = new QPushButton(play_widget);
        duck->setObjectName(QStringLiteral("duck"));
        duck->setGeometry(QRect(50, 420, 200, 200));
        duck->setStyleSheet(QStringLiteral("background-image : url(C:\\image/duck.png)"));
        camera_3 = new QLabel(play_widget);
        camera_3->setObjectName(QStringLiteral("camera_3"));
        camera_3->setGeometry(QRect(0, 12, 1280, 720));
        stacked_widget->addWidget(play_widget);
        camera_3->raise();
        apple->raise();
        bus->raise();
        cat->raise();
        duck->raise();
        result_widget = new QWidget();
        result_widget->setObjectName(QStringLiteral("result_widget"));
        great = new QLabel(result_widget);
        great->setObjectName(QStringLiteral("great"));
        great->setGeometry(QRect(140, 60, 500, 600));
        great->setStyleSheet(QStringLiteral("background-image : url(C:\\image/great.png)"));
        fail = new QLabel(result_widget);
        fail->setObjectName(QStringLiteral("fail"));
        fail->setGeometry(QRect(140, 60, 500, 600));
        fail->setStyleSheet(QStringLiteral("background-image : url(C:\\image/fail.png)"));
        return_main = new QPushButton(result_widget);
        return_main->setObjectName(QStringLiteral("return_main"));
        return_main->setGeometry(QRect(720, 260, 450, 100));
        return_main->setStyleSheet(QStringLiteral("background-image : url(C:\\image/mainButtonBasic.png)"));
        quit_button_2 = new QPushButton(result_widget);
        quit_button_2->setObjectName(QStringLiteral("quit_button_2"));
        quit_button_2->setGeometry(QRect(750, 430, 400, 80));
        quit_button_2->setStyleSheet(QStringLiteral("background-image : url(C:\\image/quitButtonBasic.png)"));
        camera_4 = new QLabel(result_widget);
        camera_4->setObjectName(QStringLiteral("camera_4"));
        camera_4->setGeometry(QRect(0, 12, 1280, 720));
        stacked_widget->addWidget(result_widget);
        camera_4->raise();
        fail->raise();
        return_main->raise();
        quit_button_2->raise();
        great->raise();
        Rhythm_GameClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Rhythm_GameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Rhythm_GameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Rhythm_GameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Rhythm_GameClass->setStatusBar(statusBar);

        retranslateUi(Rhythm_GameClass);
        QObject::connect(start_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(enter_stage()));
        QObject::connect(quit_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(exit_game()));
        QObject::connect(right_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_next_stage()));
        QObject::connect(left_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(change_before_stage()));
        QObject::connect(stage_1, SIGNAL(clicked()), Rhythm_GameClass, SLOT(play_video()));
        QObject::connect(stage_2, SIGNAL(clicked()), Rhythm_GameClass, SLOT(play_video()));
        QObject::connect(stage_3, SIGNAL(clicked()), Rhythm_GameClass, SLOT(play_video()));
        QObject::connect(return_main, SIGNAL(clicked()), Rhythm_GameClass, SLOT(enter_stage()));
        QObject::connect(quit_button_2, SIGNAL(clicked()), Rhythm_GameClass, SLOT(exit_game()));
        QObject::connect(next_button, SIGNAL(clicked()), Rhythm_GameClass, SLOT(play_game()));
        QObject::connect(bus, SIGNAL(clicked()), Rhythm_GameClass, SLOT(check_answer()));
        QObject::connect(cat, SIGNAL(clicked()), Rhythm_GameClass, SLOT(check_answer()));
        QObject::connect(duck, SIGNAL(clicked()), Rhythm_GameClass, SLOT(check_answer()));
        QObject::connect(apple, SIGNAL(clicked()), Rhythm_GameClass, SLOT(check_answer()));

        stacked_widget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Rhythm_GameClass);
    } // setupUi

    void retranslateUi(QMainWindow *Rhythm_GameClass)
    {
        Rhythm_GameClass->setWindowTitle(QApplication::translate("Rhythm_GameClass", "Rhythm_Game", 0));
        label->setText(QString());
        start_button->setText(QString());
        quit_button->setText(QString());
        camera->setText(QString());
        left_button->setText(QString());
        right_button->setText(QString());
        stage_1->setText(QString());
        stage_2->setText(QString());
        stage_3->setText(QString());
        camera_2->setText(QString());
        next_button->setText(QString());
        apple->setText(QString());
        bus->setText(QString());
        cat->setText(QString());
        duck->setText(QString());
        camera_3->setText(QString());
        great->setText(QString());
        fail->setText(QString());
        return_main->setText(QString());
        quit_button_2->setText(QString());
        camera_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rhythm_GameClass: public Ui_Rhythm_GameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RHYTHM_GAME_H
