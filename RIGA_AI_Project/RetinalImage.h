#pragma once
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class RetinalImage

{

public:
	int imageId;

private:
	string imageFilepath;


public:
	//RetinalImage(string imageSource);
	string SetFilepath(string x);
	Mat DisplayImage();

private:
	string GetFilepath();


};

