#include "stage.h"

/*
void Track::add_music(Data data)
{
Node* new_music = new Node();

new_music->data.start_music = data.start_music;
new_music->data.game_music = data.game_music;
new_music->data.music_name = data.music_name;
new_music->data.music_image = data.music_image;

new_music->before = NULL;
new_music->next = NULL;

if (Head != NULL) {
Tail->next = new_music;
new_music->before = Tail;
Tail = new_music;
}
else {
Head = Tail = new_music;
}
}

void Track::music_info()
{
music1.start_music = QUrl("C:\music/If_I_Had_a_Chicken.mp3");
music1.game_music = "C:\music/If_I_Had_a_Chicken.mp3";
music1.music_name = "If_I_Had_a_Chicken";
music1.music_image = "background-image: url(C:\\image/music_image_1.png);";

music2.start_music = QUrl("C:\music/Dog_Park.mp3");
music2.game_music = "C:\music/Dog_Park.mp3";
music2.music_name = "Dog_Park";
music2.music_image = "background-image: url(C:\\image/music_image_1.png);";

music3.start_music = QUrl("C:\music/Greenery.mp3");
music3.game_music = "C:\music/Greenery.mp3";
music3.music_name = "Greenery";
music3.music_image = "background-image: url(C:\\image/music_image_1.png);";
}

void Track::music_track()
{
add_music(music1);
add_music(music2);
add_music(music3);
}
*/

stage::stage(QObject *parent)
	: QObject(parent)
{

}

stage::~stage()
{

}

void stage::play_video()
{
	ui.main_button->show();
}
