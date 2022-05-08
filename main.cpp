// main.cpp
// (c) David Boe

#include <stdio.h>
#include <vector>
#include <stdexcept>
#include "quaternion.h"
#include "linalg.h"

using namespace std;

int main() {
    // Multiplication. x * y = 8 + -9i + -2j + 11k
    Quaternion x{ 3.0, 1.0, -2.0, 1.0 };
    //Quaternion y{ 2.0, -1.0, 2.0, 3.0 };
    Quaternion y{ 0.0, 0.0, 0.0, 0.0 };
    Quaternion z = x * y;
    
    printf("\nQuaternion multiplication:");
    printf("\nx = %s", x.repr_string().c_str());
    printf("\ny = %s", y.repr_string().c_str());
    printf("\nx * y = %s\n", z.repr_string().c_str());

    printf("\nDivision is accomplished by multiplication with the inverse:");
    try {
        // The inverse of a quaternion is not defined if its norm equals 0
        Quaternion yinv = y.inv();
    }
    catch (runtime_error& e) {
        printf("\nException occurred - %s\n", e.what());
    }
    Quaternion d = x * y.inv();
    printf("\nx * y^-1 = %s\n", d.repr_string().c_str());

    // Vector rotation
    const double t = 2 * PI / 3;
    vector<double> ax = { 1/sqrt(3), 1 / sqrt(3) , 1 / sqrt(3) };
    vector<double> v = { 1, 0, 0 }; 
    Quaternion q{ t, ax };
    vector<double> v_rotated = q.rotateVector(v);
    printf("\nRotation of a vector in a coordinate frame using a quaternion:");
    printf("\nVector coordinates before rotation are (%f, %f, %f)", v[0], v[1], v[2]);
    printf("\nVector coordinates after rotation of 2*pi/3 about (1, 1, 1) are (%f, %f, %f)\n", v_rotated[0], v_rotated[1], v_rotated[2]);

    // Frame rotation results in vecter being rotated back to its original position
    vector<double> v_frame_rotated = q.rotateFrame(v_rotated);
    printf("\nRotation of the coordinate frame using a quaternion:");
    printf("\nVector coordinates before rotation are (%f, %f, %f)", v_rotated[0], v_rotated[1], v_rotated[2]);
    printf("\nVector coordinates after rotation of the frame of 2*pi/3 about (1, 1, 1) are (%f, %f, %f)\n\n", v_frame_rotated[0], v_frame_rotated[1], v_frame_rotated[2]);
    
    return 0;
}