
#include <vector>
//#include "Rconnection.h"
#include "sisocks.h"

//#include "pch.h"
#include <sstream>
#include "ImageProcessModel.h"
#include <numeric>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "RIGA_AI_Project.h"

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include "RIGA_AI_Project.h"
#include "RetinalImageMarked.h"
#include "UnitTests.h"



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
double ReturnSum(vector<double>);
void thresh_callback(int, void*);
void conv2(Mat src, int kernel_size);
void print(vector<int> const &input);
vector<vector<string>> GetFiles(const string directory);
int main()
{
	//vector<string> filenames;
	vector<vector<string>> filenames = GetFiles("images/BinRushed2/");


	

	Mat tst1 = imread(filenames[0][1],IMREAD_GRAYSCALE);
	Mat tst2 = imread(filenames[0][0], IMREAD_GRAYSCALE);



	const char* test_window = "6-1";
	namedWindow(test_window, WINDOW_NORMAL);
	const char* test_window2 = "6-0";
	namedWindow(test_window2, WINDOW_NORMAL);

	imshow(test_window, tst1);
	imshow(test_window2, tst2);

	UnitTests ut;
	//
	Mat img = imread("image1-1.tif", IMREAD_GRAYSCALE);
	Mat img2 = imread("image1prime.tif", IMREAD_GRAYSCALE);

	Mat img3 = abs(img - img2);

	bool ut_CIRCLE_FIT_RETURN_SxRETURN = ut.CIRCLE_FIT_RETURN_SxRETURN();
	cout << "UNIT TEST:" <<endl
	<< "SxReturn:		" << ut_CIRCLE_FIT_RETURN_SxRETURN << endl 
	<< "Return Hclustering Points:		" << ut.HCLUSTERING_RETURN_POINTS() << endl;

	string source = "image1-1.tif";

	enum imgTypes { marked, unmarked, subtracted };

	RetinalImageMarked retImgMarked;

	retImgMarked.SetFilepath(source);
	retImgMarked.SetType(marked);
	


	Mat retresult = retImgMarked.DisplayImage();
	cout << "before";
	initsocks();
	cout << "after"<<endl ;


	const uint8_t* pixelPtr = (uint8_t*)img3.data;
	int cn = img3.channels();
	Scalar_<uint8_t> bgrPixel;
	vector<double> xiList;
	vector<double> yiList;

	for (int i = 0; i < img3.rows -2; i++)
	{
		for (int j = 0; j < img3.cols -2; j++)
		{
			bgrPixel.val[0] = pixelPtr[i*img3.cols*cn + j * cn + 0]; // B
			bgrPixel.val[1] = pixelPtr[i*img3.cols*cn + j * cn + 1]; // G
			bgrPixel.val[2] = pixelPtr[i*img3.cols*cn + j * cn + 2]; // R

			int*b = (int*)bgrPixel.val[0];
			int* g = (int*)bgrPixel.val[1];
			int* r = (int*)bgrPixel.val[2];

			if ((g != 000000) || (r != 000000) || (b != 000000) )
			{
				xiList.push_back(i);
				yiList.push_back(j);
			}
		}
	}
	ofstream out_xi("data/pixels/xi2.csv");
	for (const auto &e : xiList) out_xi << e << ",\n";
	out_xi.close();

	ofstream out_yi("data/pixels/yi2.csv");
	for (const auto &e : yiList) out_yi << e << ",\n";
	out_yi.close();

	cv::setBreakOnError(true);

	Mat result = imread("TestImg.tif");
	CircleFit circlefit;
	
	waitKey();
	return 0;
}


vector<vector<string>> GetFiles(const string directory)
{
	vector<vector<string>> filenames;

	for (int i = 1; i < 47; i++)
	{

		for (int j = 1; j < 7; j++)
		{

			vector<string> row;
			string prime;
			string marked;

			marked = directory + "image" + to_string(i) + "-" + to_string(j) + ".jpg";
			prime = directory + "image" + to_string(i) + "prime.jpg";

			row.push_back(prime);
			row.push_back(marked);

			filenames.push_back(row);
		}
	}

	for (int i = 0;i < filenames.size();i++)
	{
		for (int j = 0; j < filenames[i].size();j++)
		{
			
			cout<< i << ", " << j <<": " << filenames[i][j] << endl;
		}
	}

	return (filenames);
}

//Test Code	
//GREEN_ReturnPixels(img3)
	
	/*cvtColor(result, src_gray, COLOR_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));
	const char* source_window = "Source";
	namedWindow(source_window, WINDOW_NORMAL);
	imshow(source_window, result);
	const int max_thresh = 255;
	createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, thresh_callback);
	thresh_callback(0, 0);
	*/	
	/*const char* retinal_window = "retImage";
	namedWindow(retinal_window, WINDOW_NORMAL);
	imshow(retinal_window, retresult);*/	
	//cout << result;
	//namedWindow("image", WINDOW_NORMAL);
	//imshow("image", result);


	/*Rconnection *rc = new Rconnection();

	cout << "rc " << rc <<endl;

	int ic = rc->connect();

	cout << "i = " << ic << endl;
	Rvector* src = (Rvector*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RServeFunctions.r')");

	vector<int> pixelArray;
	double* arr1 = new double[xiList.size()];
	//double* arr2 = new double[yiList.size()];

	////cout << arr[0] << endl;
	//copy(xiList.begin(), xiList.end(), arr1);	
	//Rdouble* r_xiList = new Rdouble(arr1,xiList.size());

	//copy(yiList.begin(), yiList.end(), arr2);
	//Rdouble* r_yiList = new Rdouble(arr2, yiList.size());

	////Rvector *iris = (Rvector*)rc->eval("data(iris); iris");
	//
	//src = (Rvector*)rc ->eval("xi<-TestCSV();xi");
	//if (!src) { cout << "oops! couldn't get rv data\n"; delete rc; return 0; }

	////if (!rv) { cout << "oops! couldn't get data\n"; delete rc; return 0; }
	//Rdouble *sw = (Rdouble*)src->byName("xi");
	//double *swd = sw->doubleArray();

	//// and print it ...
	//{int i = 0, ct = sw->length(); while (i < ct){cout << swd[i++] << " ";}; cout << "\n"; }

	//cout << "r_xiList:	" << * r_xiList->doubleArray()<<endl;
	//cout << "r_yiList:	" << *r_yiList->doubleArray() << endl;

	//rc->assign("xi", r_xiList);
	//rc->assign("yi", r_yiList);

	//Rdouble* r_vec = (Rdouble*)rc->eval("HCluster_C(xi,yi)");
	//rc->eval("");*/

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

	const uint8_t* pixelPtr = (uint8_t*)dst.data;
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
T FunctionCall(vector<T> data, string& r_function)
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

void GREEN_ReturnPixels(Mat img3)
{
	vector<int> pixelArray;

	const uint8_t* pixelPtr = (uint8_t*)img3.data;
	int cn = img3.channels();
	Scalar_<uint8_t> bgrPixel;
	vector<double> xiList;
	vector<double> yiList;


	for (int i = 0; i < img3.rows; i++)
	{
		for (int j = 0; j < img3.cols; j++)
		{
			bgrPixel.val[0] = pixelPtr[i*img3.cols*cn + j * cn + 0]; // B
			bgrPixel.val[1] = pixelPtr[i*img3.cols*cn + j * cn + 1]; // G
			bgrPixel.val[2] = pixelPtr[i*img3.cols*cn + j * cn + 2]; // R

			int*b = (int*)bgrPixel.val[0];
			int* g = (int*)bgrPixel.val[1];
			int* r = (int*)bgrPixel.val[2];

			if ((g != 000000) || (r != 000000) || (b != 0000000))
			{
				xiList.push_back(i);
				yiList.push_back(j);

				//cout << i << " , " << j << endl;
			}

		}
	}

	vector<double> suuList;
	vector<double> suvList;
	vector<double> svuList;
	vector<double> svvList;

	vector<double> suvvList;
	vector<double> svuuList;

	vector<double> suuuList;
	vector<double> svvvList;

	for (int i = 0; i < xiList.size(); i++)
	{
		suuList.push_back(pow(xiList[i], 2));
		svvList.push_back(pow(yiList[i], 2));
		suvList.push_back(xiList[i] * yiList[i]);
		svuList.push_back(yiList[i] * xiList[i]);

		suvvList.push_back(xiList[i] * yiList[i] * yiList[i]);
		svuuList.push_back(yiList[i] * xiList[i] * xiList[i]);

		suuuList.push_back(pow(xiList[i], 3));
		svvvList.push_back(pow(xiList[i], 3));
	}

	double suu = ReturnSum(suuList);
	double svv = ReturnSum(svvList);
	double suv = ReturnSum(suvList);
	double svu = ReturnSum(svuList);

	double suuu = ReturnSum(suuuList);
	double svvv = ReturnSum(svvvList);

	double suvv = ReturnSum(suvvList);
	double svuu = ReturnSum(svuuList);

	double d[6];
	d[0] = suu;
	d[1] = suv;
	d[2] = (suuu + suvv) / 2;

	d[3] = svu;
	d[4] = svv;
	d[5] = (svvv + svuu) / 2;

	cout << "d: " << d[0] << endl << d[1] << endl << d[2] << endl << d[3] << endl << d[4] << endl << d[5] << endl << d[6] << endl;
	//Rdouble *rd = new Rdouble(d, 6);
	//rc->assign("a", rd);
	////const Rdouble *x = (Rdouble*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RHierarchicalCluster.r')");
	//const Rdouble *x = (Rdouble*)rc->eval("b<-Test3(a)");
	//cout << "R: " << x << endl << endl;
	////cout << "CircleFit suu: " << suu << endl;
	//cout << "CircleFit svv: " << svv << endl;
	//cout << "CircleFit Radius: " << r << endl;

	const char* img3_window = "retImage";
	namedWindow(img3_window, WINDOW_NORMAL);
	imshow(img3_window, img3);

	//const Rvector*data = (Rvector*)rc->eval("Test()");

}


void RIGA_AI_Project::RadiusTest()
{
	float r = Return_Radius(13, 5.2, 7, 68.25, 7);
}
void CircleFitTest()
{
	double suuu;
	double svvv;

	vector<double> suList;
	vector<double> svList;

	vector<double> suuList;
	vector<double> suvList;
	vector<double> svuList;
	vector<double> svvList;



	suList = { -1.5,-1,-0.5,0.0,0.5,1.0,1.5 };
	svList = { -3.25,-3.0,-2.25,-1.0,0.75,3.0,5.75 };

	for (int i = 0; i < suList.size(); i++)
	{
		suuList.push_back(pow(suList[i], 2));
		svvList.push_back(pow(svList[i], 2));
		suvList.push_back(suList[i] * svList[i]);
		svuList.push_back(svList[i] * suList[i]);

	}

	double suu = ReturnSum(suuList);
	double svv = ReturnSum(svvList);
	double suv = ReturnSum(suvList);
	double svu = ReturnSum(svuList);


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

double ReturnSum(vector<double> vector)
{
	double initial = 0.0;
	return std::accumulate(vector.begin(), vector.end(), initial);
}

double RIGA_AI_Project::Return_CentreY(double suu, double suv, double svu, double svv, double suuu, double svvv)
{
	double y = (svv - ((suuu * suv)/suu)/(suv -(pow(suv,2)/suu)));
	return y;
}

double RIGA_AI_Project::Return_CentreX(double suu, double suv, double svu, double svv, double suuu, double svvv)
{
	double x = (suu - ((svvv * svu) / svv) / (svu - (pow(svu, 2) / svv)));
	return x;
}


float RIGA_AI_Project::Return_ImagePixelChannels(Mat img)
{
	
	return 0;
}
