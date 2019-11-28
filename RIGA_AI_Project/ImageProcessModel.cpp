#include "pch.h"
#include "ImageProcessModel.h"

//class SubtractImageModel
//{
//	public:
//		Mat subtractedImage;
//	private:
//		Mat annotatedImage;
//		Mat primeImage;
//		Mat result;
//
	//public:
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
	
//};

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

Mat SegmentDiscsModel::ClusterSegments()
{
	Mat x;

	return x;
}