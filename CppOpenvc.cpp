// CppOpenvc.cpp: 定义应用程序的入口点。
//

#include "CppOpenvc.h"

#include <iostream>
//#include "opencv2/objdetect.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/videoio.hpp"


#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

#include <iostream>

using namespace std;
//using namespace cv;
using namespace dlib;


//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;

int main()
{
    try
    {
       
        frontal_face_detector detector = get_frontal_face_detector();
        image_window win;

        array2d<unsigned char> img;
        load_image(img, "C:\\Users\\Admin\\source\\repos\\CppOpenvc\\test.png");
		cout << "read================" << endl;
        pyramid_up(img);
        std::vector<rectangle> dets = detector(img);
		cout << "display=============" << endl;
		cout << "Number of faces detected: " << dets.size() << endl;
        win.set_image(img);
        //win.add_overlay(dets, rgb_pixel(255, 0, 0));
		cout << "Hit enter to process the next image..." << endl;
		cin.get();
    
  
    }
    catch (exception& e)
    {
        cout << "\nexception thrown!" << endl;
        cout << e.what() << endl;
    }

		
	//cout << "start openstart";
	//String face_cascade_name = samples::findFile("C:\\Users\\Admin\\source\\repos\\CppOpenvc\\lbpcascades\\lbpcascade_frontalface.xml");
	//auto cls = face_cascade.load(face_cascade_name);

	//auto img = imread("C:\\Users\\Admin\\source\\repos\\CppOpenvc\\test.png", 0);

	//vector<Rect> faces;
	//face_cascade.detectMultiScale(img, faces, 1.1, 3, 0);
	//cout << faces.size();
	//cout << "find";
	//for (size_t i = 0; i < faces.size(); i++)
	//{
	//	Point  center;
	//	int radius;
	//	center.x = cvRound((faces[i].x + faces[i].width * 0.5));
	//	center.y = cvRound((faces[i].y + faces[i].height * 0.5));
	//	radius = cvRound((faces[i].width + faces[i].height) * 0.25);
	//	circle(img, center, radius, CV_RGB(255, 0, 0), 2);
	//}
	//double scale = 0.5;
	//Size dsize = Size(img.cols * scale, img.rows * scale);

	//resize(img, img, dsize);

	//imshow("人脸识别", img);
	//cv::waitKey();
	return 0;
}
