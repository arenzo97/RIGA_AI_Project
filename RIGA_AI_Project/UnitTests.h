#pragma once

#pragma comment(lib, "Ws2_32.lib")


#include <iomanip>
#include <vector>
#include "Rconnection.h"
#include "sisocks.h"
#include <vector>
#include "CircleFit.h"
#include "HClustering.h"
#include "RetinalImage.h"

//#include "RIGA_AI_Project.h"
class UnitTests
{
public:
	bool CIRCLE_FIT_TEST();
	bool CIRCLE_FIT_RETURN_SxRETURN();
	bool HCLUSTERING_RETURN_POINTS();
	bool RETINAL_IMAGE_TEST();
	bool RETINAL_IMAGE_TEST_GetImage();
};