#include "hand.hpp"

//void Cap::ReadCam(){
//	// read Video file
//	while (cap.read(origin))	{
//		if (!isClicked) {
//			HandDetect();
//			if (contours.size() > 0)
//				Drawing(2, Detecting);
//	
//		}
//		else {
//			HandTracking();
//		}
//		
//		imshow("main", origin);
//		if (27 == waitKey(1)) Close();
//	}
//}
Mat* Cap::ReadCam(){
	cap.read(origin);
	assert(!origin.empty());

	if (!isClicked) {
		HandDetect();
		if (contours.size() > 0)
			Drawing(2, Detecting);

	}
	else {
		HandTracking();
	}
	return &origin;
}

// hsv : 0,28,115 ~ 16,122,253
//		 0,59,33 ~ 50,173,255
// ycbcr : 
void Cap::HandDetect(){
	resize(origin, origin, sz);
	flip(origin, origin, 1);
	cvtColor(origin, hand, COLOR_RGB2YCrCb);
	inRange(hand, Scalar(30, 75, 135), Scalar(255, 133, 180), hand);

	//#Q1.kernel size
	//#Q2.morphology sequence
	Mat verticalStructure = getStructuringElement(MORPH_ELLIPSE, Size(4, 4));
	erode(hand, hand, verticalStructure);
	verticalStructure = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	erode(hand, hand, verticalStructure);

	
	handROI = Mat(hand, ROI[0]);
	originROI = Mat(origin, ROI[0]);
	Mat hierarchy;
	findContours(handROI, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE, Point(0, 0));
	rectangle(origin, ROI[0], Scalar(255, 255, 0), 3); //draw ROI

	int bigsize = 0;
	//calculate biggest contour
	if (contours.size() > 0) {
		for (int i = 0; i < contours.size(); i++) {
			double a = contourArea(contours[i], false);
			if (a > bigsize) {
				bigsize = a;
				largestIndex = i;
			}
		}
		if (largestIndex >= 0) { //중심점, 손가락
			Mat center = Mat::zeros(Size(ROI[0].width, ROI[0].height), CV_8UC1);
			Mat distChange = center.clone();
			Mat cImg = center.clone();
			drawContours(center, contours, largestIndex, Scalar(255), -1);// center에 꽉찬 손 그림
			distanceTransform(center, distChange, CV_DIST_L2, 5); // distChange에 거리변환
			int maxIdx[2];    //좌표 값을 얻어올 배열(행, 열 순으로 저장됨)
			minMaxIdx(distChange, NULL, &radius, NULL, maxIdx, center);   // 반지름 설정, 최소값은 사용 X
			centerOfHand = Point(maxIdx[1], maxIdx[0]); // 중심점

			if (centerOfHand.x > 0 && centerOfHand.y > 0 && centerOfHand.x < 800 && centerOfHand.y < 720) { // 중심점이 ROI 내부에 있다면
				str.clear();
				str += "radius : ";
				str += to_string(radius);
				putText(origin, str, Point(10, 75), 0, 1, Scalar(0, 0, 255), 2);
				scale = 1.8;
				circle(cImg, centerOfHand, radius*scale, Scalar(255), 3);
				cImg = cImg & center;
				findContours(cImg, circleContour, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0)); // #circleContour를 fingerContour로 바꾸면 안디나

				int fingercount = 0, thre = 3; // 손가락 갯수
				for (int i = 0; i < circleContour.size(); i++)
					if (circleContour[i].size() > thre) fingercount++;
				if (preFingerCount - fingercount >= 4) {
					putText(origin, "click event!!", Point(10, 45), 0, 1, Scalar(0, 0, 255), 2);
					isClicked = true;
				}
				str = "finger count : ";
				str += to_string(fingercount - 1);
				putText(origin, str, Point(10, 25), 0, 1, Scalar(0, 0, 255), 2);
				preFingerCount = fingercount;
			}
		}
	}
}

void Cap::HandTracking() {
	//HandDetect();
	////bounding 코드 추가(측정값 드로우)
	//if (){ // bounding에서 찾은 object가 없으면
	//	notFoundCount++;
	//	cout << "notFoundCount:" << notFoundCount << endl;
	//	if (notFoundCount >= 100){
	//		notFoundCount = 0;
	//		foundHand = false;
	//		isClicked = false;
	//		ROI[0].x = 700, ROI[0].y = 120;
	//		return;
	//	}
	//}
	//if (!foundHand){
	//	//2.D.초기화
	//	foundHand = true;
	//	kf.predict();
	//}
	//else{
	//	kf.correct();
	//	kf.predict();
	//}
	//Drawing();

	// set dT
	double ticks = 0;
	ticks = (double)cv::getTickCount();
	double dT = (ticks - precTick) / getTickFrequency(); //seconds
	precTick = ticks;
	
	// detecting hands
	HandDetect();
	
	handsBox.clear();
	if (contours.size() > 0) {
		Rect hBox = boundingRect(contours[largestIndex]);
		handsBox.push_back(hBox);

		drawContours(originROI, contours, largestIndex, CV_RGB(0, 0, 255), 2);
		rectangle(originROI, handsBox[0], CV_RGB(0, 255, 0), 2);
		circle(originROI, centerOfHand, 2, CV_RGB(20, 150, 20), -1);
		printf("center point :(%d, %d)\nROI :(%d, %d)\n", centerOfHand.x, centerOfHand.y, ROI[0].x, ROI[0].y);

		stringstream sstr;
		sstr << "(" << centerOfHand.x << "," << centerOfHand.y << ")";
		putText(originROI, sstr.str(), Point(centerOfHand.x + 3, centerOfHand.y - 3), FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(20, 150, 20), 2);
	}
	// <<<<< Detection result Drawing

	// 여기서 계속 에러가 남.
	if (handsBox.size() == 0) {
		notFoundCount++;
		cout << "notFoundCount:" << notFoundCount << endl;
//		if (notFoundCount >= 100) {
			notFoundCount = 0;
			foundHand = false;
			isClicked = false;
			ROI[0].x = 700, ROI[0].y = 120;
			ROI[0].width = 500;
			ROI[0].height = 500;
			return;
//		}
	}
	// bounding에서 찾은 object가 없으면
	else {
		notFoundCount = 0;

		//roi상대좌표에서 절대좌표로
		measure.at<float>(0) = centerOfHand.x + ROI[0].x;
		measure.at<float>(1) = centerOfHand.y + ROI[0].y;
		measure.at<float>(2) = (float)handsBox[0].width * 1.5;
		measure.at<float>(3) = (float)handsBox[0].height * 1.5;
	}

	if (!foundHand) {

		// >>>> Initialization
		kf.errorCovPre.at<float>(0) = 1; // px
		kf.errorCovPre.at<float>(7) = 1; // px
		kf.errorCovPre.at<float>(14) = 1;
		kf.errorCovPre.at<float>(21) = 1;
		kf.errorCovPre.at<float>(28) = 1; // px
		kf.errorCovPre.at<float>(35) = 1; // px

		state.at<float>(0) = measure.at<float>(0);
		state.at<float>(1) = measure.at<float>(1);
		state.at<float>(2) = 0;
		state.at<float>(3) = 0;
		state.at<float>(4) = measure.at<float>(2);
		state.at<float>(5) = measure.at<float>(3);
		// <<<< Initialization

		kf.statePost = state;

		foundHand = true;

		//state = kf.predict();
	}
	else {
		if (notFoundCount == 0) {
			cout << "State Measure:" << endl << measure << endl;
			kf.correct(measure);
		}
		//의심이 된다
		kf.transitionMatrix.at<float>(2) = dT;
		kf.transitionMatrix.at<float>(9) = dT;
		printf("dT :%lf\n", dT);
		state = kf.predict();
		cout << "State post:" << endl << state << endl;
	}

	ROI[0].width = state.at<float>(4);
	ROI[0].height = state.at<float>(5);

	ROI[0].x = state.at<float>(0) - ROI[0].width / 2;
	if (ROI[0].x < 0) ROI[0].x = 0;
	else if (ROI[0].x + ROI[0].width > sz.width) ROI[0].width = sz.width - ROI[0].x;
	else if (ROI[0].x > sz.width || ROI[0].width < 0) {
		ROI[0].x = 700; ROI[0].width = 500;
	}

	ROI[0].y = state.at<float>(1) - ROI[0].height / 2;
	if (ROI[0].y < 0) ROI[0].y = 0;
	else if (ROI[0].y + ROI[0].height > sz.height) ROI[0].height = sz.height - ROI[0].y;
	else if (ROI[0].x > sz.width || ROI[0].width < 0) {
		ROI[0].y = 120; ROI[0].height = 500;
	}
	//>>>>>ROI 재설정

	/*Drawing(3);*/ ///predict 결과값 그리기
	Drawing(3, Tracking);
}

void Cap::Drawing(int level, int flag){
	// contours centerOfHand radius circleContour
	//contour만
	if (level == 1){
		drawContours(originROI, contours, largestIndex, Scalar(0, 0, 255), 3); //skin color contours
	}
	//원3개. 중심점,손바닥원,손가락원
	else if (level == 2){
		drawContours(originROI, contours, largestIndex, Scalar(0, 0, 255), 3); //skin color contours
		circle(originROI, centerOfHand, 2, Scalar(255, 255, 0), 3); //중심점 파란색
		circle(originROI, centerOfHand, radius, Scalar(0, 0, 255), 3); //손바닥 빨간색
		circle(originROI, centerOfHand, radius * scale, Scalar(255, 0, 255), 3); //손가락 기준되는 원 보라색

	}
	//boxing(measure)
	else if (level == 3){
		drawContours(originROI, contours, largestIndex, CV_RGB(0, 255, 0), 2);
		rectangle(originROI, handsBox[0], CV_RGB(0, 255, 255), 2);
		circle(originROI, centerOfHand, 2, CV_RGB(0, 255, 255), -1);
	}
	return;
}

void Cap::Close(){
	destroyAllWindows();
	cap.release();
}
