#include "music.h"

void Music::music()
{
	player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile("C:\music/If_I_Had_a_Chicken.mp3"));
	player->setVolume(50);
	player->play();
}