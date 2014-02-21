//#define K 2     // Number of groups = 2
//#define D 2    // Dimension = 2
//#define N 10  // Number of vectors to classify = 10
#pragma once
#include <vector>
using namespace std;
#define D1 2
// double** data permet une initialisation plus directe voir main() 

class Kmeans
{
public:
Kmeans(double data[][D1], double centroids[][D1], int D, int N, int K );
~Kmeans();
void FindGroup();
void FindCentroids();
void DisplayGpIndex();//It was to debug code : should not be ther if it is.
void DisplayCentroids();//It was to debug code : should not be ther if it is.
void DisplayGpSize();//It was to debug code : should not be ther if it is.
int _D, _N, _K;
vector<int> _gpIndex;                     //vector containing the group number of each vector.        //the N vectors of dimension D
vector< vector<double> >  _centroids;   //the K centroids
vector<int> _gpSize;   
vector< vector<double> > _data;  
                 
}; 
