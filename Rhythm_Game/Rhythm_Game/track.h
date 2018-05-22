#ifndef TRACK_H
#define TRACK_H

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <qfile.h>

#include <iostream>

#include "Image.h"
#include "ui_rhythm_game.h"

class Track
{
public:

	Image image;

	typedef struct Data//�׽�Ʈ���� ����Ʈ�� ������ ������ ����
	{ 
		QUrl    start_music; // ���� ����ȭ�鿡 ������ ª�� ����
		QString game_music;  // ���� ����
		QString music_name;  // ���� ����
		QString music_image; // ���� �ٹ�
	}Data;

	typedef struct _Node
	{
		 Data data;
		 struct _Node* next;
		 struct _Node* before;
	}Node;

	Node *Head = NULL;
	Node *Tail = NULL;
	Node *tempPoint;

	Data music1;
	Data music2;
	Data music3;

	QMediaPlayer* player;
	
	void add_music(Data data);//��� ����
	void music_info();
	void music_track();

private:
	Ui::Rhythm_GameClass ui;
};

#endif // TRACK_H