#include "RetinalImageMarked.h"

RetinalImageSubtracted::RetinalImageSubtracted()
{

};

RetinalImageSubtracted::RetinalImageSubtracted(Mat marked, Mat prime)
{
	img = abs(marked - prime);

};

void RetinalImageSubtracted::ExportToCSV(string filePath)
{
	//Get Pixels
	const uint8_t* pixelPtr = (uint8_t*)img.data;
	int cn = img.channels();
	Scalar_<uint8_t> bgrPixel;
	vector<double> xiList;
	vector<double> yiList;

	for (int i = 0; i < img.rows - 2; i++)
	{
		for (int j = 0; j < img.cols - 2; j++)
		{
			bgrPixel.val[0] = pixelPtr[i*img.cols*cn + j * cn + 0]; // B
			bgrPixel.val[1] = pixelPtr[i*img.cols*cn + j * cn + 1]; // G
			bgrPixel.val[2] = pixelPtr[i*img.cols*cn + j * cn + 2]; // R

			int*b = (int*)bgrPixel.val[0];
			int* g = (int*)bgrPixel.val[1];
			int* r = (int*)bgrPixel.val[2];

			if ((g != 000000) || (r != 000000) || (b != 000000))
			{
				xiList.push_back(i);
				yiList.push_back(j);
			}
		}
	}

	//Output to CSV
	ofstream out_xi(filePath);
	for (const auto &e : xiList) out_xi << e << ",\n";
	out_xi.close();

	ofstream out_yi(filePath);
	for (const auto &e : yiList) out_yi << e << ",\n";
	out_yi.close();
};