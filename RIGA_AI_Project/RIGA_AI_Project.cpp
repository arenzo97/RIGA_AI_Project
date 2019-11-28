// RIGA_AI_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ImageProcessModel.h"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cv::setBreakOnError(true);
	

	Mat img = imread("image1-1.tif");
	Mat img2 = imread("image1prime.tif");

	Mat result = abs(img- img2);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", result);
	waitKey(0);
	return 0;
}