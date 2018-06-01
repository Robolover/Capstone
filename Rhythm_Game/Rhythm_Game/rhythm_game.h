#ifndef RHYTHM_GAME_H
#define RHYTHM_GAME_H

#define WIDTH  1280
#define HEIGHT 720

#define TRUE  1
#define FALSE 0

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMultimedia>
#include <QMouseEvent>
#include <QTimer>

#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"

#include "ui_rhythm_game.h"
class Rhythm_Game : public QMainWindow
{
	Q_OBJECT

public:
	Rhythm_Game(QWidget *parent = 0);
	~Rhythm_Game();

	void get_mouse_state( QPoint &hand_point, int &finger);	
	void click_evet(QMouseEvent *e);
	void play_video();

	int select_stage = 1;
	int limit_stage  = 1;
	int answer_correct = 0;
	int click_flag   = FALSE;
	int finger_count = 0;
	int m_point_x = 0;
	int m_point_y = 0;

private:
	Ui::Rhythm_GameClass ui;
	QGraphicsVideoItem *item;
	QGraphicsScene *scene;
	QMediaPlayer* player;
	QVideoWidget *video;
	QMouseEvent *click;
	QTimer *timer;
	QTimer *timer_2;
	
private slots:
	void update_camera();
	void start_button();
	void exit_button();
	void change_next_stage();
	void change_before_stage();
	void chose_stage();
	void play_game();
	void check_answer();
	void result();
};

#endif // RHYTHM_GAME_H
