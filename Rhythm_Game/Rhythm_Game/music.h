#ifndef MUSIC_H
#define MUSIC_H

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>

#include "ui_rhythm_game.h"

class Music
{
public:
	void music();
	QMediaPlayer* player;

private:
	Ui::Rhythm_GameClass ui;
};
#endif // MUSIC_H