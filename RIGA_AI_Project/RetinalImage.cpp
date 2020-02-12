#include "RetinalImage.h"


//RetinalImage::RetinalImage(string imageSource)
//{
//	SetFilepath(imageSource);
//
//};


Mat RetinalImage::DisplayImage()
{
	Mat image = imread(imageFilepath);
	return image;
};

string RetinalImage::GetFilepath()
{
	return imageFilepath;
};
string RetinalImage::SetFilepath(string x)
{
	imageFilepath = x;
	return imageFilepath;
};