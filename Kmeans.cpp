#include "Kmeans.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


Kmeans::Kmeans(string data , string centroids )
{ 
	
	//// Lecture des fichiers contenant les données et centroids
 

	ifstream data2(data,ios::in);
	ifstream centroids2(centroids,ios::in);

	// récupération des données

    if(data2)  // si l'ouverture a fonctionnée
    {
		data2 >> _N ;
		data2 >> _D;

		// Allocation de la mémoire
		_data = vector< vector<double> >(_N);
		_gpIndex = vector<int>(_N);
		_centroids = vector< vector<double> >(_D);

		for(int i = 0; i< _N; i++)
		{
			_data[i] = vector<double>(_D);
			_gpIndex[i] = 0; 
	
			for (int j = 0; j < _D; j++)
			{
				data2 >> _data[i][j];
			}
		
		}
	data2.close();	
  	}
    else
    cerr << "Impossible d'ouvrir le fichier data !" << endl;



    // récupération des centroids

    if(centroids2)  // si l'ouverture a fonctionnée
    {
		centroids2 >> _K ;

		// Allocation de la mémoire
	    _gpSize = vector<int>(_K);

		for (int i = 0; i < _K; i++)
		{
			_gpSize[i] = 0;
			_centroids[i] = vector<double>(_D);

			for (int j = 0; j < _D; j++)
			{
				centroids2 >> _centroids[i][j];
			}
		}

	centroids2.close();	
  	}
    else
    cerr << "Impossible d'ouvrir le fichier centroids !" << endl;

}


Kmeans::~Kmeans(void)
{
}


void Kmeans::FindGroup()
{

	double normref = 0;  //On calcule la norme associée au premier barycentre.
    double norm = 0;    //Calcule de la norme.

    for (int i = 0; i < _K; i++)
	{
		_gpSize[i] = 0;
	}

	for (int i = 0; i < _N; i++)  //Pour chaque vecteur de data
	{
		
		for(int d = 0; d < _D; d++)
		{
			normref += (_data[i][d] - _centroids[0][d])*(_data[i][d] - _centroids[0][d]);
		}
	_gpIndex[i] = 0;  //Par défaut, on commence par dire que "i" appartient au groupe 0 (le premier groupe).

		for(int k = 1; k < _K; k++)  //On calcule chaque autre norme en la comparant avec celle associé au premier barycentre.
		{
			
			for(int d = 0; d < _D; d++)
			{
				norm += (_data[i][d] - _centroids[k][d])*(_data[i][d] - _centroids[k][d]);
			}
			if (norm < normref)  //Comparaison avec celle du premier barycentre.
			{
				normref = norm;
				_gpIndex[i] = k; //Si la norme associé au groupe k est plus petite
			}
		}
		for(int k = 0; k < _K; k++)  //incrémente la taille du groupe auquel appartient "i". (on aurait pu faire mieux ça doit pas gagner un temps considérable puisque K est typiquement petit)
		{
			if (_gpIndex[i] == k)
			{
				_gpSize[k]++;
			}
		}
	}
}

void Kmeans::FindCentroids()
{
	for (int i = 0; i < _K; i++)
	{
		for (int j = 0; j < _D ; j++)
		{
			_centroids[i][j] = 0;
		}
		
	}

	for (int i = 0; i < _N; i++)  // pour chaque "i", on cherche le groupe de "i".
	{
		for(int k = 0; k < _K; k++)
		{
			if(_gpIndex[i] == k)  //quand on trouve le bon indice k, on met à jour le vecteur temp[k].
			{
				for(int d = 0; d < _D; d++)
				{
					_centroids[k][d] += _data[i][d]/_gpSize[k];
				}
				break;
			}
		}
	}
}



void Kmeans::DisplayGpIndex()
{
	cout << " Indices :" << endl;
	for (int i = 0 ; i < _N ; i++)
	{
		cout << _gpIndex[i] << endl;
	}
}

void Kmeans::DisplayCentroids()
{
	cout << " Centroids :" << endl;
	for (int i = 0 ; i < _K ; i++)
	{
		for( int j = 0 ; j < _D ; j++)
		{
			cout << _centroids[i][j] << " " ;
		}
		cout << endl;
	}
}

void Kmeans::DisplayGpSize()
{
	cout << "Group sizes : " << endl;
	for (int i = 0 ; i < _K ; i++)
	{
		cout << _gpSize[i] << endl;
	}
 }