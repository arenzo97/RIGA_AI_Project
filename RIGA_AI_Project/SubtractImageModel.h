#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;

namespace SubtractImageModel
{
	class SubtractImage
	{
	public:
		Mat img1;
		Mat img2;
	public:
		Mat ReturnSubtractedImage(Mat img1, Mat img2);
	};
}
