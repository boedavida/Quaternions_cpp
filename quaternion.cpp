// quaternion.cpp
// (c) David Boe

#include "quaternion.h"
#include <math.h>
#include <vector>
#include <string> 
#include <stdexcept>
#include "linalg.h"

using namespace std;

// Constructors
Quaternion::Quaternion(const double a, const double b, const double c, const double d) : q0(a), q1(b), q2(c), q3(d) {};
Quaternion::Quaternion(const Quaternion & q) : q0(q.q0), q1(q.q1), q2(q.q2), q3(q.q3) {}; // Copy constructor
Quaternion::Quaternion(const double t, const vector<double>& ax) {
    // Constructor with angle and axis of rotation
    double ax_norm_inv = 1 / sqrt(dotProduct(ax, ax));
    vector<double> ax_unit = scalarVectorProduct(ax_norm_inv, ax);
    q0 = cos(t / 2);
    q1 = ax_unit[0] * sin(t / 2);
    q2 = ax_unit[1] * sin(t / 2);
    q3 = ax_unit[2] * sin(t / 2);
}

// Getters
double Quaternion::a() const { return q0; };
double Quaternion::b() const { return q1; };
double Quaternion::c() const { return q2; };
double Quaternion::d() const { return q3; };

string Quaternion::repr_string() const {
    string str = to_string(q0);
    for (double x : vector<double>{ q1, q2, q3 }) {
        if (signbit(x)) {
            str += " - " + to_string(abs(x));
        }
        else {
            str += " + " + to_string(x);
        }
    };
    return str; 
}

double Quaternion::real() const { return q0; };

vector<double> Quaternion::imaginary() const {
    return vector<double>{ q1, q2, q3 };
}

double Quaternion::norm() const {
    return sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(q0, -q1, -q2, -q3);
}

Quaternion Quaternion::inv() const {
    double n = this->norm();
    // The inverse of a quaternion is not defined if its norm equals 0 
    if (n * n == 0) {
        throw runtime_error("Math error: Attempted to divide by Zero\n");
    }
    double d = 1 / (n * n);
    vector<double> v = { q0, -q1, -q2, -q3 };
    vector<double> w = scalarVectorProduct(d, v);
    return Quaternion(w[0], w[1], w[2], w[3]);
}

vector<double> Quaternion::coef() const {
    return vector<double> {q0, q1, q2, q3};
}

// OVerload arithmetic operators
const Quaternion Quaternion::operator + (const Quaternion& rhs) const {
    return Quaternion(q0 + rhs.q0, q1 + rhs.q1, q2 + rhs.q2, q3 + rhs.q3);
}
const Quaternion Quaternion::operator - (const Quaternion& rhs) const {
    return Quaternion(q0 - rhs.q0, q1 - rhs.q1, q2 - rhs.q2, q3 - rhs.q3);
}
const Quaternion Quaternion::operator * (const Quaternion& rhs) const {
    // Quaternion multiplication is not commutative
    /*
    // Element by element computation
    double ap = q0 * rhs.q0 - q1 * rhs.q1 - q2 * rhs.q2 - q3 * rhs.q3;
    double bp = q0 * rhs.q1 + q1 * rhs.q0 + q2 * rhs.q3 - q3 * rhs.q2;
    double cp = q0 * rhs.q2 - q1 * rhs.q3 + q2 * rhs.q0 + q3 * rhs.q1;
    double dp = q0 * rhs.q3 + q1 * rhs.q2 - q2 * rhs.q1 + q3 * rhs.q0;
    */

    // Linear algebra-based computation
    vector<double> p = this->imaginary();
    vector<double> q = rhs.imaginary();
    
    vector<double> p0q = scalarVectorProduct(q0, q);
    vector<double> q0p = scalarVectorProduct(rhs.q0, p);
    vector<double> cpr = crossProduct(p, q);
    double ap = q0 * rhs.q0 - dotProduct(p, q);
    double bp = p0q[0] + q0p[0] + cpr[0];
    double cp = p0q[1] + q0p[1] + cpr[1];
    double dp = p0q[2] + q0p[2] + cpr[2];
   
    return Quaternion(ap, bp, cp, dp);
}

bool Quaternion::operator == (const Quaternion& rhs) const {
    return vector<double>{q0, q1, q2, q3} == vector<double>{rhs.q0, rhs.q1, rhs.q2, rhs.q3};
}

vector<double> Quaternion::rotateVector(vector<double> v) {
    Quaternion u = Quaternion(0, v[0], v[1], v[2]);
    Quaternion w = *this * u * this->conjugate();
    return w.imaginary();
}

vector<double> Quaternion::rotateFrame(vector<double> v) {
    Quaternion u = Quaternion(0, v[0], v[1], v[2]);
    Quaternion w = this->conjugate() * u * (* this);
    return w.imaginary();
}

