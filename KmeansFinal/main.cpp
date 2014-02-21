#include <iostream>
#include <vector>
#include <string>
#include "Kmeans.h"

using namespace std;

///////////// Création des données /////////

int main()
{



	// Kmeans


	Kmeans Km(data,centroids);

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