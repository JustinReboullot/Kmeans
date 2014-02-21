#include "data_generation_functions.h"


double fRand(int fRange) // génère des réels (avec au max un chiffre après la virgule) entre -fRange et fRange aléatoirement.
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