#include "CircleFit.h"


int CircleFit::TEST_DATA()
{
	double suuu;
	double svvv;

	vector<double> suList;
	vector<double> svList;

	vector<double> suuList;
	vector<double> suvList;
	vector<double> svuList;
	vector<double> svvList;

	vector<double> svuuList;
	vector<double> suvvList;


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

	return 0;
}


double CircleFit::Return_Sx(const vector<double>& coordList)
{

	return 0;
}


double CircleFit::Return_Radius(double uc, double vc, double suu, double svv, int length)
{

	double alpha = pow(uc, 2) + pow(vc, 2) + ((suu + svv) / length);
	double radius = sqrt(alpha);

	return radius;
}

float CircleFit::InverseMatrix(vector<float> matrix1, vector<float> matrix2)
{
	return 0.0;
}

double CircleFit::ReturnSum(vector<double> vector)
{
	double initial = 0.0;
	return std::accumulate(vector.begin(), vector.end(), initial);
}

float Return_CentreY(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float y = (svv - ((suuu * suv) / suu) / (suv - (pow(suv, 2) / suu)));
	return y;
}

float Return_CentreX(float suu, float suv, float svu, float svv, float suuu, float svvv)
{
	float x = (svv - ((suuu * suv) / suu) / (suv - (pow(suv, 2) / suu)));
	return x;
}
double CircleFit::Return_SVV(vector<double>& svList)
{
	vector<double> xList;
	double result = 0.0;
	
	for (int i = 0; i < svList.size(); i++) { xList.push_back(pow(svList[i], 2)); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SUU(vector<double>& suList)
{
	vector<double> xList;
	double result = 0.0;
	for (int i = 0; i < suList.size(); i++) { xList.push_back(pow(suList[i], 2)); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SUV(vector<double>& suList, vector<double>& svList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < svList.size(); i++) { xList.push_back(svList[i] + suList[i]); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SVU(vector<double>& suList, vector<double>& svList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < svList.size(); i++) { xList.push_back(svList[i] + suList[i]); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SUUU(vector<double>& svList, vector<double>& suList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < suList.size(); i++) { xList.push_back(pow(suList[i], 3)); }

	result = ReturnSum(suList);

	return result;
}

double CircleFit::Return_SUUV(vector<double>& svList, vector<double>& suList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < svList.size(); i++) { xList.push_back(pow(svList[i], 2)); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SUVV(vector<double>& svList, vector<double>& suList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < svList.size(); i++) { xList.push_back(pow(svList[i], 2)); }
	result = ReturnSum(xList);
	return result;
}

double CircleFit::Return_SVVV(vector<double>& svList, vector<double>& suList)
{
	vector<double> xList;
	double result = 0.0;

	for (int i = 0; i < svList.size(); i++) { xList.push_back(pow(svList[i], 2)); }
	result = ReturnSum(xList);
	return result;
}
