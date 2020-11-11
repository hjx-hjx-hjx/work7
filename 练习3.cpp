#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\sevenpic.jpg"), dstMat;
	cvtColor(srcMat, dstMat, CV_BGR2GRAY);
	Mat result, sobMat;
	threshold(dstMat, sobMat, 100, 255, THRESH_BINARY);
	Canny(sobMat, result, 100, 180, 3);
	vector <Vec4i> lines;
	HoughLinesP(result, lines, 1, CV_PI / 180, 30,30,10);
	vector<Vec4i>::iterator it = lines.begin();
	for (; it != lines.end(); ++it) {
		Point pt1, pt2;
		pt1.x = it[0][0];
		pt1.y = it[0][1];
		pt2.x = it[0][2];
		pt2.y = it[0][3];
		line(srcMat, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}
	imshow("src", srcMat);
	imshow("aaa", result);
	waitKey(0);
}