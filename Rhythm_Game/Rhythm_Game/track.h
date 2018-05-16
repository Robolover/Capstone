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

	typedef struct Data//테스트에서 리스트에 보관할 데이터 형식
	{
		QString start_music; // 음악 선택화면에 나오는 짧은 음악
		QString game_music;  // 게임 음악
		QString music_name;  // 음악 제목
		QString music_image; // 음악 앨범
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
	
	void add_music(Data* data);//노드 생성
	void track();

private:
	Ui::Rhythm_GameClass ui;
};

#endif // TRACK_H