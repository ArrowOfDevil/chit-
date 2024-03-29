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

double left_square(double a, double b, int N,double (*f)(double))
{
    double sum=0;
    double h=(b-a)/N;
    for(int i=0;i<N;i++)
    {
        sum+=f(a+i*h)*h;
    }
    return sum;
}

int main() {
    cout<<left_square(0, 10, 100000, func)<<endl;
    return 0;
}


