//RServe Tests
//DEBUG


#pragma comment(lib, "Ws2_32.lib")


#include <vector>
#include "Rconnection.h"
#include "sisocks.h"
#include <vector>
#include "RIGA_AI_Project.h"



using namespace std;



//Application tests
bool Test_VectorToString(vector<float> radius)
{

	

	return true;
}

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