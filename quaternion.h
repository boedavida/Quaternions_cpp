// quaternion.h
// (c) David Boe

#ifndef quaternion_H // include guard
#define quaternion_H

#include <string> 
#include <vector>

using namespace std;

constexpr double PI = 3.14159265358979323846;

class Quaternion {
    double q0 = 1;
    double q1 = 0;
    double q2 = 0;
    double q3 = 0;
    string qrepr;

public:

    // Constructors
    Quaternion(const double, const double, const double, const double);
    Quaternion(const double, const vector<double>&); // angle, axis of rotation
    Quaternion(const Quaternion&); // Copy constructor
    //Quaternion(const double, const double);
    ~Quaternion() {};

    // Getters
    double a() const;
    double b() const;
    double c() const;
    double d() const;

    // String printable representation
    const string & repr_string() const;

    double real() const;
    vector<double> imaginary() const;
    Quaternion conjugate() const;
    double norm() const;
    Quaternion inv() const;
    vector<double> coef() const;

    // Overload +, -, and * operators
    const Quaternion operator + (const Quaternion&) const;
    const Quaternion operator - (const Quaternion&) const;
    const Quaternion operator * (const Quaternion&) const;

    // Overload isequal operator
    bool operator == (const Quaternion&) const;

    // Rotations
    vector<double> rotateVector(vector<double>);
    vector<double> rotateFrame(vector<double>);
};

#endif // Quaternion_H