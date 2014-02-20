#define D1 2
#include <vector>

#pragma once
using namespace std;


class Kmeans
{
public:
Kmeans(double data[][D1], double centroids[][D1], int D, int N, int K );
~Kmeans();
void FindGroup();
void FindCentroids();
void DisplayGpIndex();
void DisplayCentroids();
void DisplayGpSize();
int _D, _N, _K;
vector<int> _gpIndex;  //vector containing the group number of each vector.
vector< vector<double> >  _centroids;  //the K centroids
vector<int> _gpSize;  //a vector containing the size of each group.
private:
vector< vector<double> > _data;  //the N vectors of dimension D
}; 
