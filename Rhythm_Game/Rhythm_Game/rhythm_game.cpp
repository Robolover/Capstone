#include "rhythm_game.h"

using namespace cv;
VideoCapture cap(0);

Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stacked_widget->setCurrentWidget(ui.main_widget);

	cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

	timer = new QTimer(this);
	timer->start(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
}

Rhythm_Game::~Rhythm_Game(){

}

// webcam ���� ������ capture
void Rhythm_Game::update_camera(){
	cv::Mat img;
	cv::Size(WIDTH, HEIGHT);
	cap >> img;
	QImage qimg(img.data, img.cols, img.rows, QImage::Format_RGB888);
	ui.camera->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_2->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_3->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_4->setPixmap(QPixmap::fromImage(qimg));
}

// exit_button evetn : ����
void Rhythm_Game::exit_button(){
	this->close();
}

// start_button event : ���� ����
void Rhythm_Game::start_button(){	
	ui.stacked_widget->setCurrentWidget(ui.stage_widget);
}

void Rhythm_Game::chose_stage(){
	ui.stacked_widget->setCurrentWidget(ui.video_widget);
	play_video();
}

void Rhythm_Game::play_game(){
	timer_2 = new QTimer();
	timer_2->start(5000);

	player->stop();
	ui.stacked_widget->setCurrentWidget(ui.play_widget);

	connect(timer_2, SIGNAL(timeout()), this, SLOT(result()));
}

void Rhythm_Game::play_video(){
	player = new QMediaPlayer();
	item   = new QGraphicsVideoItem;
	scene  = new QGraphicsScene();
	video  = new QVideoWidget();

	player->setVideoOutput(item);

	if (select_stage == 1)	{
		player->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	else if (select_stage == 2)	{
		player->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	else if (select_stage == 3)	{
		player->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	player->setVolume(50);

	ui.video->setViewport(video);
	player->setVideoOutput(video);
	ui.video->show();

	player->play();
}

void Rhythm_Game::change_next_stage() {
	switch (select_stage){

	case 1:
		ui.stage_1->hide();
		ui.stage_2->show();
		ui.stage_3->hide();

		select_stage = 2;
		break;

	case 2:
		ui.stage_1->hide();
		ui.stage_2->hide();
		ui.stage_3->show();

		select_stage = 3;
		break;

	case 3:
		ui.stage_1->show();
		ui.stage_2->hide();
		ui.stage_3->hide();

		select_stage = 1;
		break;

	default:
		select_stage = 1;
		break;
	}
}

void Rhythm_Game::change_before_stage() {
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

void Rhythm_Game::check_answer()
{
	answer_correct += 1;
}

void Rhythm_Game::result()
{
	if (answer_correct == 4){
		ui.stacked_widget->setCurrentWidget(ui.result_widget);
		ui.great->show();
		ui.fail->hide();

		if (limit_stage < 3){
			limit_stage += 1;
		}
	}

	else {
		ui.stacked_widget->setCurrentWidget(ui.result_widget);
		ui.great->hide();
		ui.fail->show();
	}
}

/*
void Rhythm_Game::get_mouse_state( QPoint &hand_point, int &finger)
{
	//m_point_x = hand_point.x;
	//m_point_y = hand_point.y;

	//finger_count = finger;
}

void Rhythm_Game::click_evet(QMouseEvent *e)
{
	//m_point->x;
	//m_point->y; // m_point�� button ���� ���� ���� �߰�

	int state = 0;
	
	switch (state)
	{
		case 0: 
			if (finger_count == 5)
			{
				click_flag = FALSE;
				state = 1;
			}
			break;

		case 1:
			if (finger_count == 0)
			{
				click_flag = TRUE;
				state = 2;
			}
			break;

		case 2:
			if (finger_count == 0 && click_flag == TRUE)
			{
				emit SIGNAL(clicked());
			}
			break;

		default:
			state = 0;
			break;
	}
}
*/