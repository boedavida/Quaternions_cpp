// qtest.cpp
// Unit tests for quaternion arithmatic
#include <cstdio>
//#include <vector>
//#include <math.h>
//#include <stdexcept>
#include "quaternion.h"
//#include "linalg.h"
#include "mytest.h"

constexpr bool summaryFlag = false;
unsigned long int tpass = 0, tfail = 0;

int main()
{
    printf("mytest version: %s\n", mytest::version());
    
    mytest q("quaternion arithmatic");
    q.summary(summaryFlag);
    
    printf("\nTesting Quaternion class n");
    
    // Multiplication. x * y = 8 + -9i + -2j + 11k
    Quaternion ans{ 8.0, -9.0, -2.0 + 11.0 };
    Quaternion x{ 3.0, 1.0, -2.0, 1.0 };
    Quaternion y{ 2.0, -1.0, 2.0, 3.0 };
    Quaternion z = x * y;

    q.test("z = x * y", (z == ans));

    tpass += q.passCount();
    tfail += q.failCount();
    q.report();
    
    printf("\nTotals: pass: %ld, fail: %ld\n", tpass, tfail);
    
    return 0;   
}
