//
//  main.cpp
//  zad 3
//
//  Created by Михаил Смакотин on 25.03.2024.
//

#include <iostream>
#include <cmath>

using namespace std;

double phi(double x)
{
    return (x+5/x)/2;
}

double iter(double (*phi)(double),double x0,double eps)
{
    double x2=x0;
    double x1=0;
    while(fabs(x2-x1)>eps)
    {
        x1=x2;
        x2=phi(x1);
    }
    return x1;
}

int main() {
    cout<<iter(phi, 50, 0.001)<<endl;
    return 0;
}

