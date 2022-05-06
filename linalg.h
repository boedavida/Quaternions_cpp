// Library of select linear algebra functions for vectors of length 3 for use with Quaternion class. 
// (c) David Boe

#ifndef linalg_H 
#define linalg_H
#include <vector>

using namespace std;

// Product of a scalar and a vector
vector<double> scalarVectorProduct(double, const vector<double> &);

// Dot product between two vectors
double dotProduct(const vector<double>&, const vector<double>&);

// Cross product between two vectors
vector<double> crossProduct(const vector<double>&, const vector<double>&);

#endif