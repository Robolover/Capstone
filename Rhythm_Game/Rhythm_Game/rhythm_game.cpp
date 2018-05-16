#include "rhythm_game.h"
#include "track.h"

using namespace cv;
VideoCapture cap(0);

// �����ڿ��� signal : timer slot : update_picture() �� connect ��. �ֱ�� 10msec
Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	//tempPoint = Head;
	track();

	ui.setupUi(this);

	ui.music_image->hide();
	ui.upButtonBasic->hide();
	ui.downButtonBasic->hide();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update_picture()));
	timer->start(1);
}

Rhythm_Game::~Rhythm_Game()
{

}

// webcam ���� ������ capture
void Rhythm_Game::update_picture()
{
	Mat img;
	cap >> img;
	QImage qimg(img.data, img.cols, img.rows, QImage::Format_RGB888);
	ui.camera->setPixmap(QPixmap::fromImage(qimg));
}

// exit_button evetn : ����
void Rhythm_Game::exit_button()
{
	this->close();
}

// start_button event : ���� ����
void Rhythm_Game::start_button()
{
	select_game();
}

void Rhythm_Game::select_game()
{
	ui.start_button->hide();
	ui.exit_button->hide();

	ui.music_image->show();
	ui.upButtonBasic->show();
	ui.downButtonBasic->show();

	play_music();
}

void Rhythm_Game::change_music()
{
	tempPoint = tempPoint->next;
}

void Rhythm_Game::play_music()
{
	player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile(tempPoint->data));
	player->setVolume(50);
	player->play();
}

void Rhythm_Game::chose_music()
{
	ui.music_image->hide();
	ui.upButtonBasic->hide();
	ui.downButtonBasic->hide();
}

void Rhythm_Game::add_music(QString start_music)
{
	Head = NULL;
	Node* new_music = new Node();

	new_music->data = start_music;
//	new_music->data->game_music = data->game_music;
//	new_music->data->music_name = data->music_name;
//	new_music->data->music_image = data->music_image;

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

void Rhythm_Game::track()
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

	add_music("C:\music/If_I_Had_a_Chicken.mp3");
	add_music("C:\music/Dog_Park.mp3");
	add_music("C:\music/Greenery.mp3");
}

//void Rhythm_Game::move_cursor(QMouseEvent * e)
/*{
	setMouseTracking(TRUE);  //# True ��, mouse button �ȴ�����, mouse move event ������.print(self.hasMouseTracking())
	m_pos = e->();
}
*/


