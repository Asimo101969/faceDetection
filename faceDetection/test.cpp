#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/*
//reading image
void main() {
	string path = "testImage.png";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

/*
//creating camera
void main() {
	VideoCapture video(0);
	Mat img;
	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(20);
	}
}
*/

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");
	while (true) {
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(),Scalar(30, 144, 255), 2);
			rectangle(img, Point(0, 0), Point(200, 30),Scalar(135, 206, 250), FILLED);
			putText(img, to_string(faces.size()) + "Faces Found", Point(7, 20), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 255, 255), 1, FILLED);
			putText(img, "Face Id: "+to_string(faces.size()), faces[i].tl(), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 255, 255), 1, FILLED);
		}
		imshow("Frame", img);
		waitKey(1);
	}
}