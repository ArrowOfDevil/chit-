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

double interpolate(double *U,double *X,double a)
{
    double Q[n][n];
    memset(Q, 0, sizeof(double)*n*n);
    double sum=0;
    double mult;
    for(int i=0;i<n;i++)
    {
        Q[i][0]=U[i];
        //cout<<Q[i][0];
    }
    for(int k=1;k<n;k++)
    {
        for(int i=0;i<(n-k);i++)
        {
            Q[i][k]=k*(Q[i][k-1]-Q[i+1][k-1])/(X[i]-X[i+k]);
           // cout<<Q[i][k];
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
    double U[n]={2,4,4,3,1,3,4,2};
    double X[n]={5,3,2,6,1,7,8,9};
    cout<<interpolate(U, X, 4.0);
    return 0;
}
