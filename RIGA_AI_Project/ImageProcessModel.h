#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>

using cv::Mat;
using cv::createLineSegmentDetector;

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
	private:
		float* CreateRetinalArray();
		Mat ClusterSegments();


};
