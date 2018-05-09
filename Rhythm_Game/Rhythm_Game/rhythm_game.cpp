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

// start_button event : ���� ����
void Rhythm_Game::start_button()
{
	ui.start_button->hide();
	ui.exit_button->hide();
	ui.ranking_button->hide();

	//start_game();
	image.show_image();
	QPixmap img(image.startButtonBasic);
	ui.startButtonBasic->setPixmap(image.startButtonBasic);
}

// exit_button evetn : ����
void Rhythm_Game::exit_button()
{
	this->close();
}

void Rhythm_Game::start_game()
{
//	ui.label_2->setPixmap(Image::img);
}