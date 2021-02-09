#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

const int BLANC = 255;
const int NOIR = 0;

bool chargerImage(int argc, char** argv, int readmode, Mat &img) {
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return false;
	}

 
	img = imread(argv[1], readmode);
	if (img.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void changerCouleur(Mat& I, const uchar* const table, int pixelColor) {
	CV_Assert(I.depth() == CV_8U);
	int channels = I.channels();
	int nRows = I.rows;
	int nCols = I.cols * channels;
	if (I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = I.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			p[j] = pixelColor;
		}
	}
}

void binariser(Mat &img, unsigned char seuil) {
	CV_Assert(img.depth() == CV_8U);
	int channels = img.channels();
	int nRows = img.rows;
	int nCols = img.cols * channels;
	if (img.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = img.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			if (p[j] < seuil) p[j] = 0;
			else p[j] = BLANC;
		}
	}
}

void Erosion(Mat &img)
{
	Mat erosion_dest = img.clone();

 
	for (int i = 1; i < img.rows - 1; i++)
	{
		for (int j = 1; j < img.cols - 1; j++)
		{
			if (img.at<uchar>(i - 1, j) == NOIR || img.at<uchar>(i + 1, j) == NOIR || img.at<uchar>(i, j - 1) == NOIR || img.at<uchar>(i, j + 1) == NOIR) {
				erosion_dest.at<uchar>(i, j) = NOIR;
			}
		}
	}
	 
	img = erosion_dest.clone();
}

void Dilation(Mat &img)
{
	Mat dilation_dest = img.clone();

	for (int i = 1; i < img.rows - 1; i++)
	{
		for (int j = 1; j < img.cols - 1; j++)
		{
			if (img.at<uchar>(i - 1, j) == BLANC || img.at<uchar>(i + 1, j) == BLANC || img.at<uchar>(i, j - 1) == BLANC || img.at<uchar>(i, j + 1) == BLANC) {
				dilation_dest.at<uchar>(i, j) = BLANC;
			}
		}
	}
	
	img = dilation_dest.clone();

}

int nbBalles(Mat& img) {
	CV_Assert(img.depth() == CV_8U);
	int channels = img.channels();
	int nRows = img.rows;
	int nCols = img.cols * channels;
	int nbBalles = 0;
	if (img.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = img.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			if (p[j] == BLANC) nbBalles++;
		}
	}

	return nbBalles / 3333;
}

void tracerLigne(Mat & img) {

	CV_Assert(img.depth() == CV_8U);
	int channels = img.channels();
	int nRows = img.rows;
	int nCols = img.cols * channels;
	int nbBalles = 0;
	if (img.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = img.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			if (p[j] == BLANC) {
				for (int posTracage = j - 40; posTracage < j + 40; posTracage++)
				{
					p[posTracage] = 125;
				}
				i = nRows;
				j = nCols;
			}
		}
	}
}

int main(int argc, char** argv)
{
	Mat image;
	argv[1] = "Image1Balles.png";

	chargerImage(argc, argv, IMREAD_GRAYSCALE, image);

	binariser(image, 200);

	for (int i = 0; i < 3; i++)
	{
		Erosion(image);
	}
 
	for (int i = 0; i < 2; i++)
	{
		Dilation(image);
	}

	std::cout << nbBalles(image) << "\n";

	tracerLigne(image);

	imshow("", image);

	waitKey(0);
	return 0;

	waitKey(0);

}
