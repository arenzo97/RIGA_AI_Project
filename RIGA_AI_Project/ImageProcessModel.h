#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>

using cv::Mat;
using cv::createLineSegmentDetector;
using namespace cv::flann;
using cv::watershed;
using cv::findContours;

//void thresh_callback(int, void*);

class SubtractImageModel
{
	public:
		Mat subtractedImage;

	private:
		Mat annotatedImage;
		Mat primeImage;
		Mat result;


	public:
		void SetPrimeImage(Mat inputImage);
		void SetAnnotatedImage(Mat inputImage);
		Mat ReturnSubtractedImage(Mat img1, Mat img2);
};

class SegmentDiscsModel
{
	
	public:
		Mat ReturnSegmentedImages();
		void CannyImageDetect();
	private:
		float* CreateRetinalArray();
		Mat ClusterSegments(Mat img);
		void thresh_callback(int, void*);


};


