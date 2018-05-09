#ifndef IMAGE_H
#define IMAGE_H

#include <QtWidgets/QMainWindow>
#include "ui_rhythm_game.h"
#include "Image.h"

class Image
{
	public:
		void show_image();
		QString startButtonBasic;
		QString startButtonEntered;
		QString quitButtonBasic;
		QString quitButtonEntered;
		QString rightButtonBasic;
		QString rightButtonEntered;
		QString leftButtonBasic;
		QString leftButtonEntered;
		QString backButtonBasic;
		QString backButtonEntered;
		QString good;
		QString great;
		QString miss;
		QString perfect;
		QString noteBasic;
		QString noteRoute;
		QString noteRoutePressed;

	private:
		Ui::Rhythm_GameClass ui;
};
#endif // IMAGE_H