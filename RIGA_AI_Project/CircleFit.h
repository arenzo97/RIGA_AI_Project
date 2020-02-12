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



	float InverseMatrix(vector<float> matrix1, vector<float> matrix2);
	float ReturnSum(vector<float> vector);
	float Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv);
	float Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv);
	float Return_Radius(float uc, float vc, float suu, float svv, int length);
};

