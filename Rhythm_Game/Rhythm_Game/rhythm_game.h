#ifndef RHYTHM_GAME_H
#define RHYTHM_GAME_H

#define TRUE 1

#include <QtWidgets/QMainWindow>
#include <qmouseeventtransition.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <qvideowidget.h>
#include <qmultimedia.h>
#include <QTimer>
#include <QSize>

#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"

#include "ui_rhythm_game.h"
#include "Image.h"
#include "track.h"

class Rhythm_Game : public QMainWindow
{
	Q_OBJECT

public:
	Rhythm_Game(QWidget *parent = 0);
	~Rhythm_Game();

	Image image;
	Track track;

	void move_cursor(QMouseEvent *e);
	void play_video();
	int  stage = 1;
	int  stage_limit = 1;

private:
	Ui::Rhythm_GameClass ui;
	QGraphicsVideoItem *item;
	QGraphicsScene *scene;
	QMediaPlayer* player;
	QVideoWidget *video1;
	QTimer * timer;
	QPoint m_pos;

private slots:
	void update_camera();
	void start_button();
	void exit_button();
	void change_next_stage();
	void change_before_stage();
	void chose_stage();
	void play_game();
};

#endif // RHYTHM_GAME_H
