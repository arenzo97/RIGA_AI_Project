#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#include "pch.h"
#include "ImageProcessModel.h"





Mat SubtractImageModel::ReturnSubtractedImage(Mat img1, Mat img2)
{
	result = abs(img1 - img2);
	return result;
}

void SubtractImageModel::SetPrimeImage(Mat inputImage)
{
	primeImage = inputImage;
}
void SubtractImageModel::SetAnnotatedImage(Mat inputImage)
{
	annotatedImage = inputImage;
}
	

Mat SegmentDiscsModel::ReturnSegmentedImages()
{
	Mat x;

	return x;
}

float* SegmentDiscsModel::CreateRetinalArray()
{		
	float ary[5][7];
	return *ary;
}

Mat SegmentDiscsModel::ClusterSegments(Mat img)
{
	//Mat markers = findContours(img);
	Mat result = img;
	return result;
}

void SegmentDiscsModel::CannyImageDetect()
{
	
	//Mat result = cv::imread("image1-1.tif");

	//cvtColor(result, src_gray, cv::COLOR_BGR2GRAY);
	//blur(src_gray, src_gray, cv::Size(3, 3));
	//const char* source_window = "Source";
	//cv::namedWindow(source_window, cv::WINDOW_NORMAL);
	//imshow(source_window, result);
	//const int max_thresh = 255;
	////cv::createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, thresh_callback);
	//thresh_callback(0, 0);
}
void SegmentDiscsModel::thresh_callback(int, void*)
{
	/*Mat canny_output;
	Canny(src_gray, canny_output, thresh, thresh * 2);
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++)
	{
		cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(drawing, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0);
	}
	imshow("Contours", drawing);*/
}