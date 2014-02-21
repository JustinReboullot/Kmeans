#pragma once

#include "Kmeans.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Kmeans
{
public:
Kmeans(string data, string centroids); //Kmeans constructor. The arguments are .txt. files.
~Kmeans();
void FindGroup(); //Attributes to each points a group given centroids.
void FindCentroids(); //Computes centroids coordinates given the groups.
int _D, _N, _K;
vector<int> _gpIndex;  //vector containing the group number of each vector.
vector< vector<double> >  _centroids;  //the K centroids
vector<int> _gpSize;  //a vector containing the size of each group (useful for computations).
vector< vector<double> > _data;  //the N vectors of dimension D
}; 
