#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

double integration(double(*)(double), double a,double b, int N);

double f(double x)
{
    return pow(x,0.5);
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
    double a=0,b=1;
    int N=1, r=2, s=5, p=2,q=2;
    double U[s][s];
    double R[s][s];
    double p_eff[s][s];
    memset(U,0,sizeof(double)*s*s);
    memset(R,0,sizeof(double)*s*s);
    memset(p_eff,0,sizeof(double)*s*s);
    
    for(int i=0;i<s;i++)
    {
        U[i][0]=integration(f,a, b, pow(r,i)*N);
    }
    
    for(int i=1;i<s;i++)
    {
        for(int l=0;l<i;l++)
        {
            R[i][l]=(U[i][l]-U[i-1][l])/(pow(r,(p+l*q))-1);
            U[i][l+1]=U[i][l]+R[i][l];
        }
    }
    
    for(int i=2;i<s;i++)
    {
        for(int l=0;l<(i-1);l++)
        {
            p_eff[i][l]=log(fabs(R[i-1][l]/R[i][l]))/log(r);
        }
    }
    
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<(i+1);j++)
        {
            cout<<U[i][j]<<' '<<flush;
        }
        cout<<endl<<flush;
    }
    for(int i=1;i<s;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<R[i][j]<<' '<<flush;
        }
        cout<<endl<<flush;
    }
    for(int i=2;i<s;i++)
    {
        for(int j=0;j<(i-1);j++)
        {
            cout<<p_eff[i][j]<<' '<<flush;
        }
        cout<<endl<<flush;
    }
    
    
    return 0;
}


