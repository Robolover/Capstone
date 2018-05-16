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

	if (Head != NULL) { // ��带 ó�� �߰��ϴ� ���� �ƴ϶��
		Node* Tail = Head->before; // Tail�� ����� ���� ��带 ����Ű�� �Ѵ�

		Tail->next->before = new_music; // ���� ����� ���� ���, �� ��� ����� ���� ���� ���ο� ���
		Tail->next = new_music; // ���� ����� ������ ����Ű�� ��带 ���� �߰��Ǵ� ���� ����
		new_music->next = Head; // ���� �߰��Ǵ� ����� ���� ���� ��带 ����Ű���� ����
		new_music->before = Tail; // ���� �߰��Ǵ� ����� ���� ���� ���� ���� ���� ����
	}
	else { // ��带 ó�� �߰��ϴ� ���̶��
		Head = new_music; // ���� �߰��Ǵ� ��带 ���� �����Ѵ�
		Head->next = Head; // ����� ���� ��带 ���� �����Ѵ�. �ڽ��� ù ������� ������ ���.
		Head->before = Head; // ����� ���� ��带 ���� �����Ѵ�. �ڽ��� ù ������� ������ ���.
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