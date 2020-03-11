#include <fstream>
#include "RetinalImage.h"

class RetinalImageSubtracted : public RetinalImage
{

private:
	string retinalName;
public:
	RetinalImageSubtracted();
	RetinalImageSubtracted(string name, string primeFilePath, string markedFilePath);
	void ExportToCSV(string filePath);


private:
	void SetRetinalName(string x);
	

};