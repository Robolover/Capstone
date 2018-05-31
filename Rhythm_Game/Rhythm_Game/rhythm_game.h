#ifndef RHYTHM_GAME_H
#define RHYTHM_GAME_H

#define TRUE 1

#include <QtWidgets/QMainWindow>
#include <qmouseeventtransition.h>
#include <QTimer>

#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"

#include "ui_rhythm_game.h"
#include "stage.h"
#include "game_ui.h"

class Rhythm_Game : public QMainWindow
{
	Q_OBJECT

public:
	Rhythm_Game(QWidget *parent = 0);
	~Rhythm_Game();

	void main_ui();
	void stage_ui();
	void video_ui();
	void play_ui();
	void finish_ui();

	void move_cursor(QMouseEvent *e);
	void get_mouse_position(double x, double y);
	void play_video();

	int select_stage = 1;
	int stage_state = 1;

private:
	Ui::Rhythm_GameClass ui;
	QGraphicsVideoItem *item;
	QGraphicsScene *scene;
	QMediaPlayer* player;
	QVideoWidget *video;
	QTimer * timer;
	QPoint m_pos;

private slots:
	void update_camera();
	void start_button();
	void exit_button();
	void return_main();
	void change_next_stage();
	void change_before_stage();
	void chose_stage();
	void play_game();
};

#endif // RHYTHM_GAME_H
