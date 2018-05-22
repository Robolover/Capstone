#include "rhythm_game.h"
#include "track.h"

using namespace cv;
VideoCapture cap(0);

Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.left_button->hide();
	ui.right_button->hide();
	ui.video->hide();
}

Rhythm_Game::~Rhythm_Game()
{

}

// webcam 에서 영상을 capture
void Rhythm_Game::update_camera()
{
	Mat img;
	cap >> img;
	QImage qimg(img.data, img.cols, img.rows, QImage::Format_RGB888);
	ui.camera->setPixmap(QPixmap::fromImage(qimg));
}

// exit_button evetn : 종료
void Rhythm_Game::exit_button()
{
	this->close();
}

// start_button event : 게임 시작
void Rhythm_Game::start_button()
{
	//signal : timer slot : update_picture() 이 connect 됨. 주기는 10msec
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
	timer->start(1);

	ui.start_button->hide();
	ui.exit_button->hide();

	ui.stage_1->show();
	ui.stage_2->show();
	ui.stage_3->show();
	ui.left_button->show();
	ui.right_button->show();

	// signal 의 중복을 막기위해 하나는 disconnect 를 해준다
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
}

void Rhythm_Game::chose_stage()
{
	disconnect(timer, SIGNAL(timeout()), this, SLOT(update_picture()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));

	play_video();

	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.left_button->hide();
	ui.right_button->show();
}

void Rhythm_Game::play_video()
{
	player = new QMediaPlayer();
	item = new QGraphicsVideoItem;
	scene = new QGraphicsScene();
	video1 = new QVideoWidget();

	player->setVideoOutput(item);
	player->setMedia(QUrl::fromLocalFile("C:/music/talmo.mp4"));
	player->setVolume(50);

	ui.video->setViewport(video1);
	player->setVideoOutput(video1);
	ui.video->show();

	player->play();
}

void Rhythm_Game::change_next_stage()
{
	switch (stage){

	case 1:
		ui.stage_1->setGeometry(130, 400, 60, 60);
		ui.stage_2->setGeometry(300, 340, 120, 120);
		stage = 2;
		break;

	case 2:
		ui.stage_2->setGeometry(300, 400, 60, 60);
		ui.stage_3->setGeometry(430, 340, 120, 120);
		stage = 3;
		break;

	case 3:
		ui.stage_3->setGeometry(430, 400, 60, 60);
		ui.stage_1->setGeometry(130, 340, 120, 120);
		stage = 1;
		break;

	default:
		stage = 1;
		break;
	}
}

void Rhythm_Game::change_before_stage()
{
	switch (stage){

	case 1:
		ui.stage_1->setGeometry(130, 400, 60, 60);
		ui.stage_3->setGeometry(430, 340, 120, 120);
		stage = 3;
		break;

	case 2:
		ui.stage_2->setGeometry(300, 400, 60, 60);
		ui.stage_1->setGeometry(130, 340, 120, 120);
		stage = 1;
		break;

	case 3:
		ui.stage_3->setGeometry(430, 400, 60, 60);
		ui.stage_2->setGeometry(300, 340, 120, 120);
		stage = 2;
		break;

	default:
		stage = 1;
		break;
	}
}

void Rhythm_Game::play_game()
{
	player->stop();
	ui.video->hide();

	connect(timer, SIGNAL(timeout()), this, SLOT(update_picture()));
}


//void Rhythm_Game::move_cursor(QMouseEvent * e)
/*{
	setMouseTracking(TRUE);  //# True 면, mouse button 안눌러도, mouse move event 추적함.print(self.hasMouseTracking())
	m_pos = e->();
}
*/


