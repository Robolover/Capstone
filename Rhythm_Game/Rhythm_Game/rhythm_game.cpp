#include "rhythm_game.h"

using namespace cv;
VideoCapture cap(0);

// �����ڿ��� signal : timer slot : update_picture() �� connect ��. �ֱ�� 10msec
Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

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
	start_game();
}

void Rhythm_Game::start_game()
{
	ui.start_button->hide();
	ui.exit_button->hide();
	music.music();
}

void Rhythm_Game::change_music_image()
{
	ui.music_image->setStyleSheet(QStringLiteral("background-image: url(C:\\image/music_image_2.png);"));
}

void Rhythm_Game::chose_music()
{
	ui.music_image->hide();
	ui.leftButtonBasic->hide();
	ui.rightButtonBasic->hide();
}

//void Rhythm_Game::move_cursor(QMouseEvent * e)
/*{
	setMouseTracking(TRUE);  //# True ��, mouse button �ȴ�����, mouse move event ������.print(self.hasMouseTracking())
	m_pos = e->();
}
*/


