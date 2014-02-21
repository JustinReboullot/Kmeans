#include <iostream>
#include <vector>
#include <string>
#include "Kmeans.h"

using namespace std;

///////////// Création des données /////////

int main()
{
	// definition des chemins
	// Les chemins étant relatifs, il faut que les deux fichiers de données soient
	// dans le même dossier que celui du code.
	string data;
	string centroids;
	/// Precisez l'adresse des fichiers contenant les données et les centroids.

	// Le fichier (data) contenant la données doit contenir comme premier élément
	// le nombre de ligne et comme second le nombre de colonnes puis les données.

    data = "base.txt";
	
    // Le fichier (centroids) contenant les centroids initiaux doit contenir 
    // comme premier élément le nombre de centroids puis les centroids.
	centroids = "centroids.txt";


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