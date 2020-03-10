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
	
protected:
	string imageFilepath;
	int imgType;
	int type;
	Mat img;



public:
	RetinalImage();
	RetinalImage(string imageSource);

	
	string SetFilepath(string x);
	void SetType(int _type);
	int GetType();
	string GetFilepath();
	Mat DisplayImage();

protected:
	//void ExportToCSV();
	
	//RetinalImage();
	


};

