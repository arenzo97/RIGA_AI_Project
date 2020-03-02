
#include <vector>
#include "Rconnection.h"

#include <vector>

using namespace std;

class HClustering
{

private:
	vector<double> xiList;
	vector<double> yiList;
	int listSize;


private:
	void SetXiValues(vector<double> x);
	void SetYiValues(vector<double> y);
	void SetListSize(int i);

public:
	HClustering();
	HClustering(vector<double> xi, vector<double> yi, int _listSize);
	vector<double> Cluster(vector<double> xi, vector<double> yi,int _listSize);

	vector<double> TestR(vector<double> x);

	
	vector<double> GetXiList();
	vector<double> GetYiList();
	int GetListSize();
};

