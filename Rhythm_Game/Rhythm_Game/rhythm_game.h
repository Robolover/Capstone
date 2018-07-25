#ifndef RHYTHM_GAME_H
#define RHYTHM_GAME_H

#define VIDEO_TIMER  45000 // 40段
#define INTRO_TIMER  14000 // 14段
#define GAME_TIMER   4000  // 4段
#define FINISH_TIMER 9000  // 9段

#define TRUE  1
#define FALSE 0

#include <QtWidgets/QMainWindow>
#include <QAbstractButton>
#include <QStackedWidget>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMultimedia>
#include <QMouseEvent>
#include <QCursor>
#include <QTimer>

#include "includes.h"
#include "hand.hpp"

#include "ui_rhythm_game.h"
class Rhythm_Game : public QMainWindow
{
	Q_OBJECT

public:
	Rhythm_Game(QWidget *parent = 0);
	~Rhythm_Game();

	Cap cap;

	void video_player();

	Point m_point;
	bool flag = false;
	int point_x = 0;
	int point_y = 0;
	int select_stage = 1;
	int limit_stage  = 1;
	int answer_correct = 0;

private:
	Ui::Rhythm_GameClass ui;
	QGraphicsVideoItem *item;
	QGraphicsScene *scene;
	QMediaPlayer* video_play;
	QMediaPlayer* music_play;
	QVideoWidget *video;
	QTimer *camera_timer;
	QTimer *point_timer;
	QTimer *video_timer;
	QTimer *intro_timer;
	QTimer *apple_timer;
	QTimer *bus_timer;
	QTimer *cat_timer;
	QTimer *duck_timer;
	QTimer *timer_finish;
	QCursor *cursor = new QCursor();
	QAbstractButton *b_click;

private slots:
	void click_event();
	void update_camera();
	void get_mouse_state();
	void intro_video();
	void enter_stage();
	void exit_game();
	void change_next_stage();
	void change_before_stage();
	void play_video();
	void play_game();
	void result();

	void video_function();
	void play_function();
	void answer_function();

	void apple();
	void bus();
	void cat();
	void duck();
	void finish_game();
};

#endif // RHYTHM_GAME_H
