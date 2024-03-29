//
//  main.cpp
//  zad 3
//
//  Created by Михаил Смакотин on 25.03.2024.
//

#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x*x*x-5;
}

double d_func(double x)
{
    return 3*x*x;
}

double Newtone(double (*f)(double),double (*df)(double),double x0,double eps)
{
    double x1=x0-f(x0)/df(x0);
    while(fabs(f(x1))>eps)
    {
        x1-=f(x1)/df(x1);
    }
    return x1;
}

int main() {
    cout<<Newtone(func, d_func, 50, 0.001)<<endl;
    return 0;
}
