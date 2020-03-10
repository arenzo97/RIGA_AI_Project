#include "RetinalImage.h"

RetinalImage::RetinalImage()
{

};

RetinalImage::RetinalImage(string imageSource)
{
	SetFilepath(imageSource);
	img = imread(imageFilepath, IMREAD_GRAYSCALE);
};


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
	return img;
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

