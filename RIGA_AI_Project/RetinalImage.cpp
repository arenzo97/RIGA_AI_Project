#include "RetinalImage.h"


RetinalImage::RetinalImage(string imageSource)
{


};
Mat RetinalImage::DisplayImage()
{
	Mat image = imread(imageFilepath);
	return image;
};
string RetinalImage::GetFilepath(string folderFilepath)
{
	return("Hello World");
};
string RetinalImage::SetFilepath(string x)
{
	return("Hello World");
};