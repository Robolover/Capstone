#include "track.h"

void Track::add_music(Data *data)
{
	Head = NULL;
	Node* new_music = new Node();

	new_music->data->start_music = data->start_music;
	new_music->data->game_music = data->game_music;
	new_music->data->music_name = data->music_name;
	new_music->data->music_image = data->music_image;

	new_music->before = NULL;
	new_music->next = NULL;

	if (Head != NULL) { // 노드를 처음 추가하는 것이 아니라면
		Node* Tail = Head->before; // Tail이 헤드의 이전 노드를 가리키게 한다

		Tail->next->before = new_music; // 꼬리 노드의 다음 노드, 즉 헤드 노드의 이전 노드는 새로운 노드
		Tail->next = new_music; // 꼬리 노드의 다음을 가리키는 노드를 새로 추가되는 노드로 지정
		new_music->next = Head; // 새로 추가되는 노드의 다음 노드는 헤드를 가리키도록 지정
		new_music->before = Tail; // 새로 추가되는 노드의 이전 노드는 현재 꼬리 노드로 지정
	}
	else { // 노드를 처음 추가하는 것이라면
		Head = new_music; // 새로 추가되는 노드를 헤드로 지정한다
		Head->next = Head; // 헤드의 다음 노드를 헤드로 지정한다. 자신이 첫 노드이자 마지막 노드.
		Head->before = Head; // 헤드의 이전 노드를 헤드로 지정한다. 자신이 첫 노드이자 마지막 노드.
	}
}

void Track::track()
{
	music1->start_music = "C:\music/If_I_Had_a_Chicken.mp3"; 
	music1->game_music = "C:\music/If_I_Had_a_Chicken.mp3"; 
	music1->music_name = "If_I_Had_a_Chicken"; 
	music1->music_image = "background-image: url(C:\\image/music_image_1.png);";
	
	music2->start_music = "C:\music/Dog_Park.mp3"; 
	music2->game_music = "C:\music/Dog_Park.mp3"; 
	music2->music_name = "Dog_Park"; 
	music2->music_image = "background-image: url(C:\\image/music_image_1.png);";
	
	music3->start_music = "C:\music/Greenery.mp3"; 
	music3->game_music = "C:\music/Greenery.mp3"; 
	music3->music_name = "Greenery"; 
	music3->music_image = "background-image: url(C:\\image/music_image_1.png);";

	add_music(music1);
	add_music(music2);
	add_music(music3);
}