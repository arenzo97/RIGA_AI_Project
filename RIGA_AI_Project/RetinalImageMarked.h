#include <fstream>
#include "RetinalImage.h"

class RetinalImageSubtracted : public RetinalImage
{
public:
	RetinalImageSubtracted();
	RetinalImageSubtracted(Mat prime, Mat marked);


private:
	void ExportToCSV(string filePath);

};