#include <iostream>

#include <cmath>
using namespace std;

int pres(int n) {
    double p = 3.14534452342;
    n = pow(10, n);
    p *= n;
    int k = int(p);
    p = double(k) / n;
    return p;
}