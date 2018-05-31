#ifndef GAME_UI_H
#define GAME_UI_H

#include <QObject>
#include <QMainWindow>

#include "ui_rhythm_game.h"

class game_ui : public QObject
{
	Q_OBJECT

public:
	game_ui(QObject *parent);
	~game_ui();

	void main_ui();
	void stage_ui();
	void video_ui();
	void play_ui();
	void finish_ui();

	int select_stage = 1;
	int stage_state = 1;

private:
	Ui::Rhythm_GameClass ui;
};

#endif // GAME_UI_H
