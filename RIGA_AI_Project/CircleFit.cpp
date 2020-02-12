#include "CircleFit.h"


float CircleFit::Return_Radius(float uc, float vc, float suu, float svv, int length)
{

	float alpha = pow(uc, 2) + pow(vc, 2) + ((suu + svv) / length);
	float radius = sqrt(alpha);

	return radius;
}

float CircleFit::InverseMatrix(vector<float> matrix1, vector<float> matrix2)
{
	return 0.0;
}

float CircleFit::ReturnSum(vector<float> vector)
{
	float initial = 0.0;
	return std::accumulate(vector.begin(), vector.end(), initial);
}

float CircleFit::Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float y = (svv - ((suuu * suv) / suu) / (suv - (pow(suv, 2) / suu)));
	return y;
}

float CircleFit::Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float x = (svv - ((suuu * suv) / suu) / (suv - (pow(suv, 2) / suu)));
	return x;
}

