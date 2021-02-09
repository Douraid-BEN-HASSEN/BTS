// CTraitementImage.cpp : Définit le point d'entrée pour l'application console.
//

#include "CTraitements.h"

int main()
{
	Mat image;
	image = imread("Image9Balles.png", IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Impossible de trouver l'image" << endl;
	}

	Mat image_base = image.clone();
	CTraitements traitement;

	traitement.Binarisation(image,150);
	Mat img_ero = image.clone();
	traitement.Erosion(img_ero);
	
	waitKey(0);
	traitement.VisualiserImage(image_base);
	waitKey(0);	
	traitement.VisualiserImage(image);
	waitKey(0);
	traitement.VisualiserImage(img_ero);
	waitKey(0);

	return 0;
}

