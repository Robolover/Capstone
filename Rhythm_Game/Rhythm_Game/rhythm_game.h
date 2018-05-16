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
#include <qstring.h>

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

	Image *image;

	typedef struct Data//테스트에서 리스트에 보관할 데이터 형식
	{
		QString start_music; // 음악 선택화면에 나오는 짧은 음악
		QString game_music;  // 게임 음악
		QString music_name;  // 음악 제목
		QString music_image; // 음악 앨범
	}Data;

	typedef struct Node
	{
		QString data;
		struct  Node  *next;
		struct  Node  *before;
	}Node;

	Node* Head;
	Node* tempPoint;

	Data* music1;
	Data* music2;
	Data* music3;

	void add_music(QString start_music);//노드 생성
	void track();
	void select_game();
	void move_cursor(QMouseEvent *e);
	void play_music();

private:
	Ui::Rhythm_GameClass ui;
	QMediaPlayer* player;
	QTimer * timer;
	QPoint m_pos;

private slots:
	void update_picture();
	void start_button();
	void exit_button();
	void change_music();
	void chose_music();
};

#endif // RHYTHM_GAME_H
