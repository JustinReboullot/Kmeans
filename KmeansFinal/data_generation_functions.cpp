#include "data_generation_functions.h"


double fRand(int fRange) // g�n�re des r�els (avec au max un chiffre apr�s la virgule) entre -fRange et fRange al�atoirement.
{
    double f = double( rand() % (20*fRange + 1) - 10*fRange ) / 10;
	return f;
}

void fillMatrix(vector< vector<double> >& vec, double xmax, double ymax)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j=0; j < vec[i].size(); j++)
		{
			vec[i][j] = fRand(xmax);
		}
	}	
}