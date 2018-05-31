#include "rhythm_game.h"

using namespace cv;
VideoCapture cap(0);

Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	main_ui();

	timer = new QTimer(this);
	timer->start(1);
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

void Rhythm_Game::main_ui()
{
	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.main_button->hide();
	ui.left_button->hide();
	ui.right_button->hide();
	ui.video->hide();
}

void Rhythm_Game::stage_ui()
{
	ui.start_button->hide();
	ui.exit_button->hide();
	ui.main_button->hide();

	ui.left_button->show();
	ui.right_button->show();

	if (stage_state == 1)	   { ui.stage_1->show(); }
	else if (stage_state == 2) { ui.stage_2->show(); }
	else if (stage_state == 3) { ui.stage_3->show(); }
}

void Rhythm_Game::video_ui()
{
	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.left_button->hide();
	ui.right_button->show();
}

void Rhythm_Game::play_ui()
{
	ui.video->hide();

	ui.stage_1->hide();
	ui.stage_2->hide();
	ui.stage_3->hide();
	ui.main_button->show();
	ui.right_button->hide();
}

void Rhythm_Game::finish_ui()
{
	return;
}

// exit_button evetn : 종료
void Rhythm_Game::exit_button()
{
	this->close();
}

// start_button event : 게임 시작
void Rhythm_Game::start_button()
{
	stage_ui();
	
	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(change_next_stage()));
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
}

void Rhythm_Game::chose_stage()
{
	video_ui();
	play_video();

	disconnect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(change_next_stage()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
}

void Rhythm_Game::play_game()
{
	player->stop();
	play_ui();

	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(change_next_stage()));
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
}

void Rhythm_Game::return_main()
{
	stage_ui();

	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
	connect(ui.right_button, SIGNAL(clicked()), this, SLOT(change_next_stage()));
	disconnect(ui.right_button, SIGNAL(clicked()), this, SLOT(play_game()));
	//if (stage_state < 3)	{ stage_state += 1; }
}

void Rhythm_Game::play_video()
{
	player = new QMediaPlayer();
	item   = new QGraphicsVideoItem;
	scene  = new QGraphicsScene();
	video  = new QVideoWidget();

	if (select_stage == 1) // 파랑
	{
		player->setVideoOutput(item);
		player->setMedia(QUrl::fromLocalFile("C:/music/talmo.mp4"));
		player->setVolume(50);

		ui.video->setViewport(video);
		player->setVideoOutput(video);
		ui.video->show();

		player->play(); 
	}

	else if (select_stage == 2) // 빨강
	{
		player->setVideoOutput(item);
		player->setMedia(QUrl::fromLocalFile("C:/music/timo.mp4"));
		player->setVolume(50);

		ui.video->setViewport(video);
		player->setVideoOutput(video);
		ui.video->show();

		player->play();
	}

	else if (select_stage == 3) // 초록
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
		ui.stage_1->hide();
		ui.stage_2->hide();
		ui.stage_3->show();

		select_stage = 3;
		break;

	case 2:
		ui.stage_1->show();
		ui.stage_2->hide();
		ui.stage_3->hide();

		select_stage = 1;
		break;

	case 3:
		ui.stage_1->hide();
		ui.stage_2->show();
		ui.stage_3->hide();

		select_stage = 2;
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
		ui.stage_1->hide();
		ui.stage_2->hide();
		ui.stage_3->show();

		select_stage = 3;
		break;

	case 2:
		ui.stage_1->show();
		ui.stage_2->hide();
		ui.stage_3->hide();

		select_stage = 1;
		break;

	case 3:
		ui.stage_1->hide();
		ui.stage_2->show();
		ui.stage_3->hide();

		select_stage = 2;
		break;

	default:
		select_stage = 1;
		break;
	}
}



