#define K1 2 
#define D1 2 
#define N1 10 


#include <iostream>
#include <vector>
#include "Kmeans.h"

using namespace std;

///////////// Création des données /////////

int main()
{
	double d[N1][D1];
	for (int i = 0 ; i < 5 ; i++)
	{
		d[i][0] = 1 + double(i)/10;
		d[i][1] = 1 - double(i)/10;
	}
	for (int i = 5 ; i < 10 ; i++)
	{
		d[i][0] = -1 + double(i - 5)/10;
		d[i][1] = -1 - double(i - 5)/10;
	}

	for (int i = 0 ; i < N1 ; i++)
	{
		cout << d[i][0] << " " << d[i][1] << endl;
	}


	double c[K1][D1];
	c[0][0] = -0.5;
	c[0][1] = 0.5;
	c[1][0] = 0.5;
	c[1][1] = -0.5;

/////////////////////////////////////////////////


	Kmeans Km(d,c,2,10,2);

	 Km.DisplayCentroids(); 
	 Km.DisplayGpSize();
	 Km.FindGroup();
	 Km.DisplayGpSize();
	 Km.DisplayGpIndex();
	 Km.FindCentroids();

	Km.DisplayCentroids();
	Km.FindGroup();
	Km.DisplayGpSize();
	Km.DisplayGpIndex();
	Km.FindCentroids();

	Km.DisplayCentroids();
	Km.FindGroup();
	Km.DisplayGpSize();
	Km.DisplayGpIndex();
	return 0;
}