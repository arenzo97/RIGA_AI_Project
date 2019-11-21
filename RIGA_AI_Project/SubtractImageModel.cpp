#include "pch.h"
#include "SubtractImageModel.h"

using namespace SubtractImageModel;

Mat SubtractImage::ReturnSubtractedImage(Mat img1, Mat img2)
	{
		Mat result = abs(img1 - img2);
		return result;
	}
