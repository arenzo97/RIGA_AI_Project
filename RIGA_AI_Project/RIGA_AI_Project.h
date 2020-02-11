#pragma comment(lib, "Ws2_32.lib")
//
//#define __LITTLE_ENDIAN__ 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

//#include "pch.h"
#include "ImageProcessModel.h"
#include <numeric>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "RIGA_AI_Project.h"


#include <sstream>
#include <iostream>
#include <iterator>

//
//#define MAIN         // we are the main program, we need to define this
//#define SOCK_ERRORS  // we will use verbose socket errors

//RServe headers
#include "Rconnection.h"
#include "sisocks.h"
//#include "Rsrv.h"


using namespace std;
using namespace cv;




class RIGA_AI_Project {


public:

	template <typename T>
	T FunctionCall(vector<T> data, string r_function);
	void RadiusTest();
	//void CircleFitTest();
	


	float InverseMatrix(vector<float> matrix1, vector<float> matrix2);
	float ReturnSum(vector<float> vector);
	float Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv);

	float Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv);

	float Return_ImagePixelChannels(Mat img);
};