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
	RetinalImage(string imageSource);
	Mat DisplayImage();
private:
	string GetFilepath(string folderFilepath);
	string SetFilepath(string x);

};

