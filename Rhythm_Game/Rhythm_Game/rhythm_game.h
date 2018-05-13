#ifndef RHYTHM_GAME_H
#define RHYTHM_GAME_H

#define TRUE 1

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <qmouseeventtransition.h>
#include <QIcon>
#include <QSize>
#include <QPixmap>
#include <QBitmap>

#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"

#include "ui_rhythm_game.h"
#include "Image.h"
#include "music.h"

class Rhythm_Game : public QMainWindow
{
	Q_OBJECT

public:
	Image image;
	Music music;

	Rhythm_Game(QWidget *parent = 0);
	~Rhythm_Game();
	void start_game();
	void move_cursor(QMouseEvent *e);


private:
	Ui::Rhythm_GameClass ui;
	QTimer * timer;
	QPoint m_pos;

private slots:
	void update_picture();
	void start_button();
	void exit_button();
	void change_music_image();
	void chose_music();
};

#endif // RHYTHM_GAME_H
