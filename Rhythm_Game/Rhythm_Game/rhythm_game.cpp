#include "rhythm_game.h"
#include "track.h"

using namespace cv;
VideoCapture cap(0);

// �����ڿ��� signal : timer slot : update_picture() �� connect ��. �ֱ�� 10msec
Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	//track->tempPoint = track->Head;

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
	track->tempPoint = track->tempPoint->next;
}

void Rhythm_Game::play_music()
{
	player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile(track->tempPoint->data->start_music));
	player->setVolume(50);
	player->play();
}

void Rhythm_Game::chose_music()
{
	ui.music_image->hide();
	ui.upButtonBasic->hide();
	ui.downButtonBasic->hide();
}

//void Rhythm_Game::move_cursor(QMouseEvent * e)
/*{
	setMouseTracking(TRUE);  //# True ��, mouse button �ȴ�����, mouse move event ������.print(self.hasMouseTracking())
	m_pos = e->();
}
*/


