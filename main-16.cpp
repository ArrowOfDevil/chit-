//
//  main.cpp
//  zad 16
//
//  Created by Михаил Смакотин on 25.03.2024.
//

#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return exp(x-40);
}

double gold(double a, double b, double (*f)(double))
{
    double phi=(3-sqrt(5))/2;
    double g=a+(b-a)*phi;
    double h=b-(b-a)*phi;
    double fu1=f(g);
    double fu2=f(h);
    for(int i=0;i<100;i++)
    {
        if(fu1<=fu2)
        {
            b=h;
            h=g;
            fu2=fu1;
            g=a+(b-a)*phi;
            fu1=f(g);
        }
        else
        {
            a=g;
            g=h;
            h=a+(b-a)*(1-phi);
            fu2=f(h);
        }
    }
    return f(h);
}

int main(int argc, const char * argv[]) {
    double a=40;
    double b=50;
    cout<<gold(a, b, func);
    return 0;
}
