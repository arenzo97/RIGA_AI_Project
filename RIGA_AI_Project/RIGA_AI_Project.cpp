
#include <vector>
//#include "Rconnection.h"
#include "sisocks.h"

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
#include "RIGA_AI_Project.h"
#include "RetinalImageMarked.h"

#include "CircleFit.h"

using namespace std;
using namespace cv;

Mat src_gray;
int thresh = 100;
RNG rng(12345);
float uc;
float vc;

void CircleFitTest();
float Return_Radius(float, float, float, float, int);
float Return_CentreX(float, float, float, float, float, float);
float Return_CentreY(float, float, float, float, float, float);
float ReturnSum(vector<float>);
void thresh_callback(int, void*);
void conv2(Mat src, int kernel_size);
void print(vector<int> const &input);
int main()
{

	initsocks();

	Rconnection *rc = new Rconnection();
	int i = rc->connect();
	Rconnection* src = (Rconnection*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RHierarchicalCluster.r')");
	
	

	cv::setBreakOnError(true);
	//const uchar* const table;

	Mat img = imread("image1-1.tif");
	Mat img2 = imread("image1prime.tif");

	Mat img3 = abs(img- img2);
	Mat result = imread("TestImg.tif");
	vector<int> pixelArray;
	conv2(img3, 100);
	uint8_t* pixelPtr = (uint8_t*)img3.data;
	int cn = img3.channels();
	Scalar_<uint8_t> bgrPixel;

	vector<int>b;
	
	for (int i = 0; i < img3.rows; i++)
	{
		for (int j = 0; j < img3.cols; j++)
		{
			bgrPixel.val[0] = pixelPtr[i*img3.cols*cn + j * cn + 0]; // B
			bgrPixel.val[1] = pixelPtr[i*img3.cols*cn + j * cn + 1]; // G
			bgrPixel.val[2] = pixelPtr[i*img3.cols*cn + j * cn + 2]; // R

			b.push_back((int)bgrPixel.val[0]);


			int* g = (int*)bgrPixel.val[1];
			int* r = (int*)bgrPixel.val[2];

			
		}
	}
	//cout << b;
	print(b);
	


	Rvector*data = (Rvector*)rc->eval("Test()");
	
	if (!data) { cout << "Error!"; delete rc; return 0; }
	
	cout << data << endl;
	
	//cout << bgrPixel;

	/*cvtColor(result, src_gray, COLOR_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));
	const char* source_window = "Source";
	namedWindow(source_window, WINDOW_NORMAL);
	imshow(source_window, result);
	const int max_thresh = 255;
	createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, thresh_callback);
	thresh_callback(0, 0);
	*/

	CircleFit circlefit;
	string source = "image1-1.tif";

	enum imgTypes { marked, unmarked, subtracted };
	
	RetinalImageMarked retImgMarked;

	retImgMarked.SetFilepath(source);
	retImgMarked.SetType(marked);
	//

	Mat retresult = retImgMarked.DisplayImage();


	const char* retinal_window = "retImage";
	namedWindow(retinal_window, WINDOW_NORMAL);
	imshow(retinal_window, retresult);

	cout << "CircleFit class: "<< circlefit.Return_Radius(13, 5.2, 7, 68.25, 7);
	cout << "retImgMarked type: " << retImgMarked.GetType() << endl<< "retImgMarked filepath: " << retImgMarked.GetFilepath();
	//cout << result;
	//namedWindow("image", WINDOW_NORMAL);
	//imshow("image", result);
	waitKey();
	return 0;
}

//Test Code
void print(vector<int> const &input)
{
	for (int i = 0; i < input.size();i++) 
	{
		cout << input.at(i);
	}
}
void conv2(Mat src, int kernel_size)
{
	Mat dst, kernel;
	kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
	const uint8_t* arr[3] = {0,0,0};
	/// Apply filter
	filter2D(src, dst, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	namedWindow("filter2D Demo", WINDOW_NORMAL);imshow("filter2D Demo", dst);

	uint8_t* pixelPtr = (uint8_t*)dst.data;
	int cn = dst.channels();
	Scalar_<uint8_t> bgrPixel;

	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			bgrPixel.val[0] = pixelPtr[i*dst.cols*cn + j * cn + 0]; // B
			bgrPixel.val[1] = pixelPtr[i*dst.cols*cn + j * cn + 1]; // G
			bgrPixel.val[2] = pixelPtr[i*dst.cols*cn + j * cn + 2]; // R

			// do something with BGR values...
		//	bool isEqual = (memcmp(bgrPixel, arr, MAX_DIGEST_LENGTH) == 0);

		}
	}
}
template <typename T>
T FunctionCall(vector<T> data, string r_function)
{
	string functionCall;
	functionCall.append("CircleFit(");
	std::ostringstream vts;
	if (!data.empty())
	{
		std::copy(data.begin(), data.end() - 1,
			std::ostream_iterator<int>(vts, ","));
		vts << data.back();
	}
	functionCall.append(vts.str());
	functionCall.append(")");
}
//

void RIGA_AI_Project::RadiusTest()
{
	float r = Return_Radius(13, 5.2, 7, 68.25, 7);
}
void CircleFitTest()
{
	float suuu;
	float svvv;

	vector<float> suList;
	vector<float> svList;

	vector<float> suuList;
	vector<float> suvList;
	vector<float> svuList;
	vector<float> svvList;



	suList = { -1.5,-1,-0.5,0.0,0.5,1.0,1.5 };
	svList = { -3.25,-3.0,-2.25,-1.0,0.75,3.0,5.75 };

	for (int i = 0; i < suList.size(); i++)
	{
		suuList.push_back(pow(suList[i], 2));
		svvList.push_back(pow(svList[i], 2));
		suvList.push_back(suList[i] * svList[i]);
		svuList.push_back(svList[i] * suList[i]);

	}

	float suu = ReturnSum(suuList);
	float svv = ReturnSum(svvList);
	float suv = ReturnSum(suvList);
	float svu = ReturnSum(svuList);


	float r = Return_Radius(13.3, 5.2, suu, svv, 7);
	//(uc, vc, float suu, float svv, int length)

	cout << "CircleFit suu: " << suu << endl;
	cout << "CircleFit svv: " << svv << endl;
	cout << "CircleFit Radius: " << r << endl;

}


// Functional Code
void thresh_callback(int, void*)
{
	Mat canny_output;
	Canny(src_gray, canny_output, thresh, thresh * 2);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
	}
	imshow("Contours", drawing);

	float r = Return_Radius(13, 5.2, 7, 68.25, 7);

	cout << "Radius: " << r << endl;

	CircleFitTest();
}

float Return_Radius(float uc, float vc, float suu, float svv, int length)
{

	float alpha = pow(uc, 2) + pow(vc, 2) + ((suu + svv) / length);
	float radius = sqrt(alpha);

	return radius;
}

float RIGA_AI_Project::InverseMatrix(vector<float> matrix1, vector<float> matrix2)
{
	return 0.0;
}

float ReturnSum(vector<float> vector)
{
	float initial = 0.0;
	return std::accumulate(vector.begin(), vector.end(), initial);
}

float RIGA_AI_Project::Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float y = (svv - ((suuu * suv)/suu)/(suv -(pow(suv,2)/suu)));
	return y;
}

float RIGA_AI_Project::Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float x = (svv - ((suuu * suv) / suu) / (suv - (pow(suv, 2) / suu)));
	return x;
}


float RIGA_AI_Project::Return_ImagePixelChannels(Mat img)
{
	/*uint8_t* pixelPtr = (uint8_t*)img.data;
	int cn = img.channels();
	Scalar_<uint8_t> bgrPixel;
	vector<vector<float>> pixelArray;
	vector<float> channelValues;

	for (int i = 0; i < img.cols; i++) {

		for (int j = 0; j < img.rows;j++)
		{

			float& px1 = (float&)bgrPixel.val[0] = pixelPtr[i*img.cols*cn + j * cn + 0];
			float& px2 = (float&)bgrPixel.val[1] = pixelPtr[i*img.cols*cn + j * cn + 1];
			float& px3 = (float&)bgrPixel.val[2] = pixelPtr[i*img.cols*cn + j * cn + 2];

			channelValues.push_back(px1);
			channelValues.push_back(px2);
			channelValues.push_back(px3);

			pixelArray.push_back(channelValues);
		}
		return 0;
	}*/
	return 0;
}
