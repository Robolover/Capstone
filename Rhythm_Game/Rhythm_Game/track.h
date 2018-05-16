#ifndef TRACK_H
#define TRACK_H

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>

#include <iostream>

#include "Image.h"
#include "ui_rhythm_game.h"

class Track
{
public:
	Image image;

	typedef struct Data//�׽�Ʈ���� ����Ʈ�� ������ ������ ����
	{
		QString start_music; // ���� ����ȭ�鿡 ������ ª�� ����
		QString game_music;  // ���� ����
		QString music_name;  // ���� ����
		QString music_image; // ���� �ٹ�
	}Data;

	typedef struct _Node
	{
		struct  Data *data;
		struct _Node *next;
		struct _Node *before;
	} Node;

	Node* Head;
	Node* tempPoint;
	
	Data* music1;
	Data* music2;
	Data* music3;
	
	void add_music(Data* data);//��� ����
	void track();

private:
	Ui::Rhythm_GameClass ui;
};

#endif // TRACK_H