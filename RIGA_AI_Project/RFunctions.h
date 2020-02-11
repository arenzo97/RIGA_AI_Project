#pragma once

#pragma comment(lib, "Ws2_32.lib")


#define __LITTLE_ENDIAN__ 1
#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#define MAIN 
#define SOCK_ERRORS  // we will use verbose socket errors

#include <vector>
#include "Rconnection.h"
#include "sisocks.h"





using namespace std;

class RFunctions
{
	public:
		int RServe_FunctionCall(vector<float> radius);
		int RServe_Connect_Test();
};

