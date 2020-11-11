#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\sevenpic.jpg"),dstMat;
	cvtColor(srcMat, dstMat, CV_BGR2GRAY);
	Mat result,sobMat;
	threshold(dstMat, sobMat, 100, 255, THRESH_BINARY);
	Canny(sobMat, result, 100, 180, 3);
	vector <Vec2f> lines;
	HoughLines(result, lines, 1, CV_PI / 180, 93);
	vector<Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it) {
		Point pt1, pt2;
		float rho = (*it)[0], theta = (*it)[1];
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = saturate_cast<int>(y0 - 1000 * (a));
		line(srcMat, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}
	imshow("src", srcMat);
	imshow("aaa", result);
	waitKey(0);
}