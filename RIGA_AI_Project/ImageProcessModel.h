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


	public:
		Mat SetPrimeImage(Mat inputImage);
		Mat SetAnnotatedImage(Mat inputImage);
		Mat ReturnSubtractedImage(Mat img1, Mat img2);
};

class SegmentDiscsModel
{
	public:
		Mat subtractedImage;
	

	public:
		Mat ReturnSegmentedImages();
	private:
		float CreateRetinalArray();
		Mat ClusterSegments();


};
