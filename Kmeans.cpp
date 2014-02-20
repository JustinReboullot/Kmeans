#include "Kmeans.h"
#include <iostream>
#include <vector>
using namespace std;


Kmeans::Kmeans(double data[][D1] , double centroids[][D1] , int D, int N, int K)
{ 
	_D = D;
	_N = N;
	_K = K; 

	// Allocation de la mémoire
	_data = vector< vector<double> >(_N);
	_gpIndex = vector<int>(_N);
	_centroids = vector< vector<double> >(_D);
    _gpSize = vector<int>(_K);

	//// Copie des valeurs

	for(int i = 0; i< _N; i++)
	{
		_data[i] = vector<double>(_D);
		_gpIndex[i] = 0; 
	
		for (int j = 0; j < D; j++)
		{
			_data[i][j] = data[i][j];
		}
		
	}

	for (int i = 0; i < _K; i++)
	{
		_gpSize[i] = 0;
		_centroids[i] = vector<double>(_D);

		for (int j = 0; j < _D; j++)
		{
			_centroids[i][j] = centroids[i][j];
		}
	}
}


Kmeans::~Kmeans(void)
{
}




void Kmeans::FindGroup()
{
	//memset(_gpSize, 0, sizeof(_gpSize)); //Initializes the size of each group to zero.
	double normref = 0;//On calcule la norme associée au premier barycentre.
    double norm = 0;//Calcule de la norme.

    for (int i = 0; i < _K; i++)
	{
		_gpSize[i] = 0;
	}

	for (int i = 0; i < _N; i++)//Pour chaque vecteur de data
	{
		
		for(int d = 0; d < _D; d++)
		{
			normref += (_data[i][d] - _centroids[0][d])*(_data[i][d] - _centroids[0][d]);
		}
	_gpIndex[i] = 0;//Par défaut, on commence par dire que "i" appartient au groupe 0 (le premier groupe).

		for(int k = 1; k < _K; k++)//On calcule chaque autre norme en la comparant avec celle associé au premier barycentre.
		{
			
			for(int d = 0; d < _D; d++)
			{
				norm += (_data[i][d] - _centroids[k][d])*(_data[i][d] - _centroids[k][d]);
			}
			if (norm < normref)//Comparaison avec celle du premier barycentre.
			{
				normref = norm;
				_gpIndex[i] = k; //Si la norme associé au groupe k est plus petite
			}
		}
		for(int k = 0; k < _K; k++)//incrémente la taille du groupe auquel appartient "i". (on aurait pu faire mieux ça doit pas gagner un temps considérable puisque K est typiquement petit)
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

	for (int i = 0; i < _N; i++)// pour chaque "i", on cherche le groupe de "i".
	{
		for(int k = 0; k < _K; k++)
		{
			if(_gpIndex[i] == k)//quand on trouve le bon indice k, on met à jour le vecteur temp[k].
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