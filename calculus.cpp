#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    if (x < 0) x = -x; // cos(x) = cos(-x)
    x = x - floor(x / (2 * M_PI)) * 2 * M_PI; // x = x - 2*pi*floor(x/(2*pi))
    double term = 1;
    double cosx = 0;
    double eps = 1e-9;
    for (int n = 0; term >= eps || -term >= eps; n += 2) {
        cosx += term;
        term = -term * x * x / (n+1) / (n+2);
    }
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return myCos(M_PI/2-x);
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    if (x == 0) return 0;
    double t = 1;
    double eps = 1e-9;
    while (true) {
        double inv = x / t;
        double next = (t + inv) / 2;
        // std::cout << "t: " << t << ", inv: " << inv << ", next: " << next << std::endl;
        t = next;
        // std::cout << "inv-t: " << inv-t << ", t-inv:" << t-inv << std::endl;
        if (inv - t < eps && t - inv < eps) break;
    }
    return t;
}