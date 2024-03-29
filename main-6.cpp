//
//  main.cpp
//  zad 6
//
//  Created by Михаил Смакотин on 25.03.2024.
//

#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x*x*x;
}

double sr_square(double a, double b, int N,double (*f)(double))
{
    double sum=0;
    double h=(b-a)/N;
    for(int i=0;i<N;i++)
    {
        sum+=f(a+i*h+h/2)*h;
    }
    return sum;
}

int main() {
    cout<<sr_square(0, 10, 100, func);
    return 0;
}
