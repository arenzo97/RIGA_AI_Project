//RServe Tests
//DEBUG
#include "UnitTests.h"



using namespace std;


bool UnitTests::RETINAL_IMAGE_TEST()
{
	bool result = false;

	string filePath = "images/BinRushed2/image1-1.jpg";

	RetinalImage ri(filePath);

	
	if (ri.GetFilepath() == filePath)
	{
		result = true;
		cout << "ri: " <<ri.GetFilepath() << endl;

	}
	return result;
}

bool UnitTests::RETINAL_IMAGE_TEST_GetImage()
{
	bool result = false;

	string filePath = "images/BinRushed2/image1-1.jpg";

	RetinalImage ri(filePath);

	Mat img = ri.DisplayImage();

	if (!img.empty())
	{
		result = true;
		const char* test_window = "UNIT TEST RETURN IMAGE";
		namedWindow(test_window, WINDOW_NORMAL);
		imshow(test_window, ri.DisplayImage());

	}
	return result;
}

bool UnitTests::CIRCLE_FIT_TEST()
{
	bool testResult = false;

	double suu = 0.0;
	double svv = 0.0;

	CircleFit cf;
	vector<double> uiList = { -1.5,-1,-0.5,0.0,0.5,1.0,1.5 };
	vector<double> viList = { -3.25,-3.0,-2.25,-1.0,0.75,3.0,5.75 };

	for (int i = 0; i < uiList.size(); i++)
	{
		
	}

	double suRes = cf.ReturnSum(uiList);
	double svRes = cf.ReturnSum(viList);



	if (suRes == 0)
		testResult = true;
	

	return testResult;
}

bool UnitTests::CIRCLE_FIT_RETURN_SxRETURN()
{
	CircleFit cf;
	bool result;
	const vector<double> xList = { 0,0.5,1,1.5,2,2.5,3 };
	const vector<double> suList = { -1.5,-1,-0.5,0,0.5,1,1.5};
	vector<double> sxList;

	
	
	for (int i = 0; i < xList.size(); i++)
	{
		double sx;
		sx = cf.Return_Sx(xList,xList.at(i));
		sxList.push_back(sx);
		cout << "sxList.at("<< i <<")"<< "sx = " << sxList.at(i) << endl;
		if (sxList.at(i) == suList.at(i))
			result = true;
		else
			result = false;
	}

	return result;
}


bool UnitTests::HCLUSTERING_RETURN_POINTS()
{
	
	bool result;
	vector<double> d = { 0,0.5,1,1.5,2,2.5,3 };
	HClustering hc(d,d,d.size());

	vector<double> _cluster = hc.Cluster();

	if (_cluster.size() != NULL || _cluster.size() != 0) 
	{ 
		result = true; 
	}
	else
	{
		result = false;
	}
	return result;
}

//Application tests

bool DOES_READ_FROM_FILE()
{
	return true;
}


//RSERVE Tests
bool ConnectToRServe(Rconnection *rc)
{
	/*bool i = rc->connect();
	if (i) {
		char msg[128];
		sockerrorchecks(msg, 128, -1);
		printf("unable to connect (result=%d, socket:%s).\n", i, msg); return i;
	}*/

	return false;
}

bool ConnectToRServeFunction(Rconnection *rc, string functionName)
{
	/*bool i = rc->connect();
	if (i) {
		char msg[128];
		sockerrorchecks(msg, 128, -1);
		printf("unable to connect (result=%d, socket:%s).\n", i, msg); return i;
	}*/
	Rconnection* src = (Rconnection*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RHierarchicalCluster.r')");

	return false;
}