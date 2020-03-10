#include "RetinalImage.h"


void RetinalImage::SetType(int _type)
{
	type = _type;
};


int RetinalImage::GetType()
{
	return type;
};

Mat RetinalImage::DisplayImage()
{
	string imgSrc = RetinalImage::GetFilepath();
	Mat image = imread(imgSrc);
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