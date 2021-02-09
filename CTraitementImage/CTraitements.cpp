#include "CTraitements.h"


CTraitements::CTraitements()
{
	namedWindow("Image", WINDOW_AUTOSIZE);
}


CTraitements::~CTraitements()
{
}

void CTraitements::AquisitionNouvelleImage(void) {

}

void CTraitements::VisualiserImage(Mat &img) {
	imshow("Image", img);
}

void CTraitements::Binarisation(Mat &img, int seuil) {
	cvtColor(img, img, COLOR_BGR2GRAY);
	////Binarisation
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
	//Image noir/blanc
	for (i = 0; i < nRows; ++i)
	{
		p = img.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			if (p[j] > seuil)
			{
				p[j] = BLANC;
			}
			else {
				p[j] = NOIR;
			}
		}
	}
}

void CTraitements::Erosion(Mat &img_bin) {
	Mat Copie_img = img_bin.clone();
		int channels = Copie_img.channels();
		int nRows = Copie_img.rows;
		int nCols = Copie_img.cols * channels;

		if (Copie_img.isContinuous())
		{
			nCols *= nRows;
			nRows = 1;
		}

		int i, j;
		uchar* p;
		uchar* h;
		uchar* b;

			//Carré
			//Var
			int largeur;
			int hauteur;
			int depart_x;
			int depart_y;
			//Initialisation
			depart_x = 0;
			depart_y = 0;
			largeur = Copie_img.cols;
			hauteur = Copie_img.rows;

			// Ligne Haut
			p = Copie_img.ptr<uchar>(depart_y);
			for (j = depart_x; j < (largeur+ depart_x); ++j)
			{
				p[j] = BLANC;
			}
			// Ligne Bas
			p = Copie_img.ptr<uchar>(hauteur+ depart_y);
			for (j = depart_x; j < (largeur + depart_x); ++j)
			{
				p[j] = BLANC;
			}
			//Barre Gauche
			for (i = depart_y; i < (hauteur + depart_y); ++i)
			{
				p = Copie_img.ptr<uchar>(i);
				p[depart_x] = BLANC;
			}
			//Barre Gauche
			for (i = depart_y; i < (hauteur + depart_y); ++i)
			{
				p = Copie_img.ptr<uchar>(i);
				p[depart_x + largeur] = BLANC;
			}
		//

	for (i = 1; i < nRows-1; ++i)
	{
		p = img_bin.ptr<uchar>(i);
		for (j = 1; j < nCols-1; ++j)
		{
			h = img_bin.ptr<uchar>(i-1);
			b = img_bin.ptr<uchar>(i + 1);
			if (h[j] == NOIR || b[j] == NOIR || p[j-1] == NOIR || p[j+1] == NOIR) {
				p[j] = NOIR;
			}
			else {
				p[j] = BLANC;
			}
		}
	}
}

void CTraitements::DenombrerNombreDeBalle(void) {

}