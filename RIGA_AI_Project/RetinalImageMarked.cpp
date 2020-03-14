#include "RetinalImageMarked.h"

RetinalImageSubtracted::RetinalImageSubtracted()
{

};

RetinalImageSubtracted::RetinalImageSubtracted(string name, string primeFilePath, string markedFilePath)
{
	SetRetinalName(name);
	Mat marked = imread(markedFilePath,IMREAD_GRAYSCALE);

	//resize(marked, marked, marked.size(),0.1,0.1);
	Mat prime = imread(primeFilePath, IMREAD_GRAYSCALE);
	//resize(prime, prime, prime.size(), 0.1, 0.1);
	img = abs(marked - prime);
	threshold(img, img, 47, 255, 0);

	

};

void RetinalImageSubtracted::ExportToCSV(string filePath)
{
	//Get Pixels
	//threshold(img, img, 50, 255, 0);
	const uint8_t* pixelPtr = (uint8_t*)img.data;
	int cn = img.channels();
	Scalar_<uint8_t> bgrPixel;
	string imgName_filePath = filePath + retinalName + ".txt";

	ofstream imgName(imgName_filePath);
	imgName << retinalName;
	imgName.close();

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
	string xi_filePath = filePath + retinalName +"_values.csv";
	//string yi_filePath = filePath + retinalName + "_yi.csv";

	ofstream out_csvi(xi_filePath);

	for (int i = 0; i < xiList.size();i++)
	{
		out_csvi << retinalName << "," << xiList.at(i) << "," << yiList.at(i) << endl;
	}
	out_csvi.close();
	//for (const auto &e : xiList) out_xi << e << "\n";
	//	//out_xi.close();
	////ofstream out_yi(yi_filePath);
	//for (const auto &e : yiList) out_xi << e << "\n";
	//out_xi.close();

	
};

void RetinalImageSubtracted::SetRetinalName(string x)
{
	retinalName = x;
};