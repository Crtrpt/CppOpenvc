// CppOpenvc.cpp: 定义应用程序的入口点。
//

#include "CppOpenvc.h"

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;


CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

int main()
{

	cout << "start openstart";
	String face_cascade_name = samples::findFile("C:\\Users\\Admin\\source\\repos\\CppOpenvc\\lbpcascades\\lbpcascade_frontalface.xml");
	auto cls = face_cascade.load(face_cascade_name);

	auto img = imread("C:\\Users\\Admin\\source\\repos\\CppOpenvc\\test.png", 0);

	vector<Rect> faces;
	face_cascade.detectMultiScale(img, faces, 1.1, 3, 0);
	cout << faces.size();
	cout << "find";
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point  center;
		int radius;
		center.x = cvRound((faces[i].x + faces[i].width * 0.5));
		center.y = cvRound((faces[i].y + faces[i].height * 0.5));
		radius = cvRound((faces[i].width + faces[i].height) * 0.25);
		circle(img, center, radius, CV_RGB(255, 0, 0), 2);
	}
	double scale = 0.5;
	Size dsize = Size(img.cols * scale, img.rows * scale);

	resize(img, img, dsize);

	imshow("人脸识别", img);
	cv::waitKey();
	return 0;
}
