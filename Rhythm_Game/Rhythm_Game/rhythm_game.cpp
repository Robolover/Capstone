#include "rhythm_game.h"

using namespace cv;

Rhythm_Game::Rhythm_Game(QWidget *parent)
	: QMainWindow(parent)
{	
	ui.setupUi(this);
	ui.stacked_widget->setCurrentWidget(ui.main_widget);
	//emit intro_video();
	
	camera_timer = new QTimer(this);
	camera_timer->start(1);
	connect(camera_timer, SIGNAL(timeout()), this, SLOT(update_camera()));
}

Rhythm_Game::~Rhythm_Game(){

}

// webcam 에서 영상을 capture
void Rhythm_Game::update_camera(){
	cv::Mat* img;
	img = cap->ReadCam();

	QImage qimg((uchar*)img->data, img->cols, img->rows, QImage::Format_RGB888);
	ui.camera->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_2->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_3->setPixmap(QPixmap::fromImage(qimg));
	ui.camera_4->setPixmap(QPixmap::fromImage(qimg));
}

void Rhythm_Game::intro_video(){
	video_play = new QMediaPlayer();
	item = new QGraphicsVideoItem;
	scene = new QGraphicsScene();
	video = new QVideoWidget();

	video_play->setVideoOutput(item);
	video_play->setMedia(QUrl::fromLocalFile("C:/music/intro.mp4"));
	video_play->setVolume(50);

	ui.intro_video->setViewport(video);
	video_play->setVideoOutput(video);
	ui.intro_video->show();

	video_play->play();
}

// exit_button evetn : 종료
void Rhythm_Game::exit_game(){
	this->close();
}

// start_button event : 게임 시작
void Rhythm_Game::enter_stage(){	
	ui.stacked_widget->setCurrentWidget(ui.stage_widget);
}

void Rhythm_Game::play_video(){
	ui.stacked_widget->setCurrentWidget(ui.video_widget);
	emit video_function();
}

void Rhythm_Game::play_game(){
	ui.stacked_widget->setCurrentWidget(ui.play_widget);
	emit play_function();
}

void Rhythm_Game::video_function(){
	video_timer = new QTimer();
	//video_timer->start(VIDEO_TIMER);

	//ui.next_button->hide();
	video_player();

	connect(video_timer, SIGNAL(timeout()), ui.next_button, SLOT(show()));
}

void Rhythm_Game::play_function(){
	video_play->stop();

	music_play = new QMediaPlayer;
	music_play->setMedia(QUrl::fromLocalFile("C:/music/video_1.mp3"));
	music_play->setVolume(50);
	music_play->play();

	intro_timer = new QTimer();	
	intro_timer->start(INTRO_TIMER);

	connect(intro_timer, SIGNAL(timeout()), this, SLOT(apple()));
}

void Rhythm_Game::apple(){
	intro_timer->stop();

	apple_timer = new QTimer();
	apple_timer->start(GAME_TIMER);

	connect(ui.apple, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(apple_timer, SIGNAL(timeout()), this, SLOT(bus()));
}

void Rhythm_Game::bus(){
	apple_timer->stop();

	bus_timer = new QTimer();
	bus_timer->start(GAME_TIMER);

	disconnect(ui.apple, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(ui.bus, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(bus_timer, SIGNAL(timeout()), this, SLOT(cat()));
}

void Rhythm_Game::cat(){
	bus_timer->stop();

	cat_timer = new QTimer();
	cat_timer->start(GAME_TIMER);

	disconnect(ui.bus, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(ui.cat, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(cat_timer, SIGNAL(timeout()), this, SLOT(duck()));
}

void Rhythm_Game::duck(){
	cat_timer->stop();

	duck_timer = new QTimer();
	duck_timer->start(GAME_TIMER);

	disconnect(ui.cat, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(ui.duck, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(duck_timer, SIGNAL(timeout()), this, SLOT(finish_game()));
}

void Rhythm_Game::finish_game(){
	duck_timer->stop();

	timer_finish = new QTimer();
	timer_finish->start(FINISH_TIMER);

	disconnect(ui.duck, SIGNAL(clicked()), this, SLOT(check_answer()));
	connect(timer_finish, SIGNAL(timeout()), this, SLOT(result()));
}

void Rhythm_Game::answer_function(){
	answer_correct += 1;
}

void Rhythm_Game::result(){
	timer_finish->stop();

	if (answer_correct == 4){
		ui.stacked_widget->setCurrentWidget(ui.result_widget);
		ui.great->show();
		ui.fail->hide();

		//if (limit_stage < 3){
		//	limit_stage += 1;
		//}
	}

	else {
		ui.stacked_widget->setCurrentWidget(ui.result_widget);
		ui.great->hide();
		ui.fail->show();
	}
}

void Rhythm_Game::video_player(){
	video_play = new QMediaPlayer();
	item       = new QGraphicsVideoItem;
	scene      = new QGraphicsScene();
	video      = new QVideoWidget();

	video_play->setVideoOutput(item);

	if (select_stage == 1)	{
		video_play->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	else if (select_stage == 2)	{
		video_play->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	else if (select_stage == 3)	{
		video_play->setMedia(QUrl::fromLocalFile("C:/music/stage_1.mp4"));
	}

	video_play->setVolume(50);

	ui.video->setViewport(video);
	video_play->setVideoOutput(video);
	ui.video->show();

	video_play->play();
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

void Rhythm_Game::get_mouse_state(){
	flag = cap->qt_flag;

	if (flag == TRUE){
		m_point = cap->GetPoint();
	}
}

void Rhythm_Game::click_evet(Ui::Rhythm_GameClass *ui)
{
	//ui->	
}