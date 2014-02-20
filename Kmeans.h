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
void DisplayGpIndex();
void DisplayCentroids();
void DisplayGpSize();
int _D, _N, _K;
vector<int> _gpIndex;                     //vector containing the group number of each vector.
vector< vector<double> > _data;          //the N vectors of dimension D
vector< vector<double> >  _centroids;   //the K centroids
vector<int> _gpSize;   
private:
                 //a vector containing the size of each group.
}; 
