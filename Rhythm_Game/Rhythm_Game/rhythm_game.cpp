#include "rhythm_game.h"

using namespace cv;
VideoCapture cap(0);

Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.main_button->hide();
	ui.left_button->hide();
	ui.right_button->hide();
	ui.video->hide();

	timer = new QTimer(this);
	timer->start(1);
}

Rhythm_Game::~Rhythm_Game()
{

}

// webcam ���� ������ capture
void Rhythm_Game::update_camera()
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
	//signal : timer slot : update_picture() �� connect ��. �ֱ�� 10msec
	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));

	ui.start_button->hide();
	ui.exit_button->hide();

	ui.stage_1->show();
	ui.stage_2->show();
	ui.stage_3->show();
	ui.left_button->show();
	ui.right_button->show();

	// signal �� �ߺ��� �������� �ϳ��� disconnect �� ���ش�
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(next_stage()));
}

void Rhythm_Game::chose_stage()
{
	timer->stop();
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
	video = new QVideoWidget();

	if (stage_state == 1)
	{
		player->setVideoOutput(item);
		player->setMedia(QUrl::fromLocalFile("C:/music/talmo.mp4"));
		player->setVolume(50);

		ui.video->setViewport(video);
		player->setVideoOutput(video);
		ui.video->show();

		player->play();

	}

	else if (stage_state == 2)
	{
		player->setVideoOutput(item);
		player->setMedia(QUrl::fromLocalFile("C:/music/timo.mp4"));
		player->setVolume(50);

		ui.video->setViewport(video);
		player->setVideoOutput(video);
		ui.video->show();

		player->play();

	}


	else if (stage_state == 3)
	{
		player->setVideoOutput(item);
		player->setMedia(QUrl::fromLocalFile("C:/music/mario.mp4"));
		player->setVolume(50);

		ui.video->setViewport(video);
		player->setVideoOutput(video);
		ui.video->show();

		player->play();

	}
}

void Rhythm_Game::change_next_stage()
{
	switch (select_stage){

	case 1:
		ui.stage_1->setGeometry(130, 400, 60, 60);
		ui.stage_2->setGeometry(300, 340, 120, 120);
		stage_state = 2;
		select_stage = 2;
		break;

	case 2:
		ui.stage_2->setGeometry(300, 400, 60, 60);
		ui.stage_3->setGeometry(430, 340, 120, 120);
		stage_state = 3;
		select_stage = 3;
		break;

	case 3:
		ui.stage_3->setGeometry(430, 400, 60, 60);
		ui.stage_1->setGeometry(130, 340, 120, 120);
		stage_state = 1;
		select_stage = 1;
		break;

	default:
		select_stage = 1;
		break;
	}
}

void Rhythm_Game::change_before_stage()
{
	switch (select_stage){

	case 1:
		ui.stage_1->setGeometry(130, 400, 60, 60);
		ui.stage_3->setGeometry(430, 340, 120, 120);
		stage_state = 3;
		select_stage = 3;
		break;

	case 2:
		ui.stage_2->setGeometry(300, 400, 60, 60);
		ui.stage_1->setGeometry(130, 340, 120, 120);
		stage_state = 1;
		select_stage = 1;
		break;

	case 3:
		ui.stage_3->setGeometry(430, 400, 60, 60);
		ui.stage_2->setGeometry(300, 340, 120, 120);
		stage_state = 2;
		select_stage = 2;
		break;

	default:
		select_stage = 1;
		break;
	}
}

void Rhythm_Game::play_game()
{
	timer->start(1);
	
	player->stop();
	ui.video->hide();

	ui.main_button->show();

	connect(timer, SIGNAL(timeout()), this, SLOT(update_picture()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(next_stage()));
}

void Rhythm_Game::next_stage()
{
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(next_stage()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));

	timer->stop();

	stage_state += 1;
	if (stage_state > 3) { stage_state = 1; }

	play_video();
}

void Rhythm_Game::return_main()
{

	ui.start_button->hide();
	ui.exit_button->hide();
	ui.main_button->hide();

	ui.stage_1->show();
	ui.stage_2->show();
	ui.stage_3->show();
	ui.left_button->show();
	ui.right_button->show();

	// signal �� �ߺ��� �������� �ϳ��� disconnect �� ���ش�
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
}

//void Rhythm_Game::move_cursor(QMouseEvent * e)
/*{
	setMouseTracking(TRUE);  //# True ��, mouse button �ȴ�����, mouse move event ������.print(self.hasMouseTracking())
	m_pos = e->();
}
*/


