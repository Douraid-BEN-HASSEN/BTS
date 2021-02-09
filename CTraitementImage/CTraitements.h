#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

#define NOIR 0
#define BLANC 255

using namespace cv;
using namespace std;

class CTraitements
{
public:
	CTraitements();
	~CTraitements();

	void AquisitionNouvelleImage(void);
	void VisualiserImage(Mat &);
	void Binarisation(Mat &, int);
	void Erosion(Mat &);
	void DenombrerNombreDeBalle();

};

