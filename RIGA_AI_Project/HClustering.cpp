#include "HClustering.h"

//HClustering::HClustering(){}

HClustering::HClustering(vector<double> xi, vector<double> yi, int _listSize)
{
	SetXiValues(xi);
	SetYiValues(yi);
	SetListSize(_listSize);
}

vector<double> HClustering::TestR(vector<double> x)
{
	return x;
}

vector<double> HClustering::Cluster()
{
	/*initsocks();
	Rconnection *rc = new Rconnection();
	
	int i = rc->connect();
	const Rconnection* src = (Rconnection*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RServeFunctions.r')");

	double* h_arr = xiList.data();

	Rdouble* r_xiList = new Rdouble(h_arr,xiList.size());
	rc->assign("arr",r_xiList);
	rc->eval("TestReturnDoubleList(arr)");
*/
	return GetXiList();
	

}


void HClustering::SetXiValues(vector<double> x)
{
	xiList = x;
}

void HClustering::SetYiValues(vector<double> y)
{
	xiList = y;
}
void HClustering::SetListSize(int i)
{
	listSize = i;
}



vector<double> HClustering::GetXiList()
{
	return xiList;
}
vector<double> HClustering::GetYiList()
{
	return yiList;
}
int HClustering::GetListSize()
{
	return listSize;
}