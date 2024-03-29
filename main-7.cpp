#include <iostream>

double integration(double(*)(double), double a,double b, int N);

double U(double x)
{
    return 1/(1+(x*x));
}

double integration(double (*func)(double), double a,double b, int N){
    double intg=0,h=0,x=a;
    h=(b-a)/N;
    for(int i=0;i<N;i++)
    {
        intg=intg+(func(x+(i+1)*h)+func(x+i*h))*h/2;
    }
    return intg;
}

int main() {
    double a=-1, b=1;
    for(int i=1;i<256; i*=2)
    {
        std::cout<<integration(U, a, b, i)<<std::endl;
    }
    return 0;
}
