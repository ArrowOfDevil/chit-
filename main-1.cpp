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
    return x*x*x-27;
}

double dih(double (*f)(double),double a,double b,double eps)
{
    while(fabs(b-a)>eps)
    {
        if(f(a)*f((a+b)/2)<0)
        {
            b=(a+b)/2;
        }
        else if(f(a)==0)
        {
            b=a;
        }
        else if(f(b)==0)
        {
            a=b;
        }
        else
        {
            a=(a+b)/2;
        }
    }
    return (a+b)/2;
}

int main() {
    cout<<dih(func,-20,20, 0.001)<<endl;
    return 0;
}

