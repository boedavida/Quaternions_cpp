// Library of select linear algebra functions for vectors of length 3 for use with Quaternion class. 
// (c) David Boe

#include <vector>
#include <numeric>      // std::inner_product
#include "linalg.h"

using namespace std;

// Product of a scalar and a vector
vector<double> scalarVectorProduct(double s, const vector<double> & v) {
    vector<double> w;
    for (double i : v) {
        w.push_back(s * i);
    }
    return w;
}

// Dot product between two vectors of length 3
double dotProduct(const vector<double> & a, const vector<double> & b) {
    return inner_product(a.begin(), a.begin() + 3, b.begin(), 0.0);
}

// Cross product between two vectors of length 3
vector<double> crossProduct(const vector<double>& a, const vector<double>& b) {
    vector<double> cp(3);
    cp[0] = a[1] * b[2] - a[2] * b[1];
    cp[1] = -(a[0] * b[2] - a[2] * b[0]);
    cp[2] = a[0] * b[1] - a[1] * b[0];
    return cp;
}
