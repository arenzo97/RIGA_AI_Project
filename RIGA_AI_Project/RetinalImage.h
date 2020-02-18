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
	int imgType;
	int type;


public:
	//RetinalImage(string imageSource);
	//RetinalImage();
	//RetinalImage(char* setFilepath[], int setType);
	string SetFilepath(string x);
	void SetType(int _type);
	int GetType();
	string GetFilepath();
	Mat DisplayImage();

private:

	//RetinalImage();
	


};

