#include "RFunctions.h"



int RFunctions::RServe_FunctionCall(vector<float> radius)
{
	initsocks();

	Rconnection *rc = new Rconnection();
	int i = rc->connect();
	const Rconnection* src = (Rconnection*)rc->eval("source('C:/Projects/CS3072/FinalYearProject/RIGA_AI_Project/RIGA_AI_Project/RHierarchicalCluster.r')");
	vector<double> radiusConv;


	for (int i = 0; i < radius.size(); i++)
	{
		radiusConv.push_back(radius[i]);
	}



	double d[1] = { 1 };

	int ia[6] = { 1, 4, 6, 3, 5 , 2 };
	Rinteger *ri = new Rinteger(ia, 6);
	rc->assign("i", ri);


	delete rc;
	return 0;
}



//DEMO from RSERVE
int RFunctions::RServe_Connect_Test()
{
	initsocks(); // this is needed for Win32 - it does nothing on unix

	Rconnection *rc = new Rconnection();

	int i = rc->connect();
	if (i) {
		char msg[128];
		sockerrorchecks(msg, 128, -1);
		printf("unable to connect (result=%d, socket:%s).\n", i, msg); return i;
	}

	double d[6] = { 1.5, 2.4, 5.6, -1.2, 0.6, 1.7 };

	// assign the above contents to the variable "a" in R
	Rdouble *rd = new Rdouble(d, 6);
	rc->assign("a", rd);
	delete rd;

	// create a 2 x 3 matrix named "b" and calculate b * t(b) matrix product
	Rdouble *x = (Rdouble*)rc->eval("b<-matrix(a,2); b%*%t(b)");

	if (x) { // if everything was fine, we have the result
		cout << x << "\n";

		// just for fun - let's get the matrix dimensionality
		Rinteger *dim = (Rinteger*)x->attribute("dim");
		if (dim)
			cout << dim->intAt(0) << " by " << dim->intAt(1) << " matrix\n";

		// and print the contents of the matrix (unformatted)
		double *d = x->doubleArray();
		int i = 0, ct = x->length();
		while (i < ct) { cout << d[i++] << " "; }
		cout << "\n";

		// finally dispose of the object
		delete x;
	}

	// integer constant assignment test
	int ia[6] = { 1, 4, 6, 3, 5 , 2 };
	Rinteger *ri = new Rinteger(ia, 6);
	rc->assign("i", ri);
	delete ri;

	// let's get the whole iris data
	Rvector *iris = (Rvector*)rc->eval("data(iris); iris");
	if (!iris) { cout << "oops! couldn't get iris data\n"; delete rc; return 0; }

	// now let's just get the sepal width - this a cheap operation, no talking to Rserve, because we have all the data already
	Rdouble *sw = (Rdouble*)iris->byName("Sepal.Width");
	double *swd = sw->doubleArray();

	// and print it ...
	{ int i = 0, ct = sw->length(); while (i < ct) { cout << swd[i++] << " "; }; cout << "\n"; }


	delete iris;

	// dispose the connection object - this implicitly closes the connection
	delete rc;

}