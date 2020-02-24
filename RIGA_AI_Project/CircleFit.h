#pragma once

#include <sstream>
#include <numeric>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class CircleFit
{
public:
	//void RadiusTest();
	//void CircleFitTest();



	int TEST_DATA();
	float InverseMatrix(vector<float> matrix1, vector<float> matrix2);
	double ReturnSum(vector<double> vector);
	float Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv);
	float Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv);
	double Return_Radius(double uc, double vc, double suu, double svv, int length);

	double Return_Sx(const vector<double>& coordList, double coordVal, int size);
	
	double Return_SVV(vector<double>& svList);
	double Return_SUU(vector<double>& suList);
	double Return_SUV(vector<double>& suList, vector<double>& svList);
	double Return_SVU(vector<double>& suList, vector<double>& svList);


	double Return_SUUU(vector<double>& svList, vector<double>& suList);
	double Return_SUUV(vector<double>& svList, vector<double>& suList);
	double Return_SUVV(vector<double>& svList, vector<double>& suList);
	double Return_SVVV(vector<double>& svList, vector<double>& suList);
};

