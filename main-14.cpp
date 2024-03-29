//
//  main.cpp
//  zad 13
//
//  Created by Михаил Смакотин on 24.03.2024.
//

#include <iostream>

#define n 8

using namespace std;

int fac(int x)
{
    int q=1;
    for(int i=1;i<(x+1);i++)
        q*=i;
    return q;
}

double solution(double *U,double *X,double a)
{
    double Q[n][n];
    memset(Q, 0, sizeof(double)*n*n);
    double sum=0;
    double mult;
    for(int i=0;i<n;i++)
    {
        Q[i][0]=U[i];
    }
    for(int k=1;k<n;k++)
    {
        for(int i=0;i<(n-k);i++)
        {
            Q[i][k]=k*(Q[i][k-1]-Q[i+1][k-1])/(X[i]-X[i+k]);
        }
    }
    for(int k=0;k<n;k++)
    {
        mult=1;
        for(int i=0;i<k;i++)
        {
            mult*=(a-X[i]);
        }
        sum=sum+(mult*Q[0][k])/fac(k);
    }
    return sum;
}

int main() {
    double U[n]={0,1,2,3,4,5,6,7};
    double X[n]={-1,0,1,2,3,4,5,6};
    cout<<solution(X, U, 5.5);
    return 0;
}
