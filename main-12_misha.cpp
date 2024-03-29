//
//  main.cpp
//  zad 12
//
//  Created by Михаил Смакотин on 23.03.2024.
//

#include <iostream>
#include <cmath>
using namespace std;

void printvec(double *vec,int s);

double vecpr(double *A,double *B,int s)
{
    double q=0;
    for(int i=0;i<s;i++)
    {
        q+=A[i]*B[i];
    }
    return q;
}

double *matpr(double **A,double *X,int s)
{
    double *Q;
    Q = new double[s];
    memset(Q, 0, sizeof(double)*s);
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            Q[i]+=A[i][j]*X[j];
        }
    }
    return Q;
}

double *rar(double **A,double *X,double *B, int s)
{
    double *r;
    double *Ax;
    r = new double[s];
    Ax = new double[s];
    Ax = matpr(A, X, s);
    for(int i=0;i<s;i++)
    {
        r[i]=Ax[i]-B[i];
    }
    return r;
}

double tau(double **A, double *r,int s)
{
    double *Ar;
    double q;
    Ar = new double[s];
    Ar=matpr(A, r, s);
    q=vecpr(Ar, r, s)/vecpr(Ar, Ar, s);
    return q;
}

void printvec(double *vec,int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<vec[i]<<' '<<flush;
    }
    cout<<endl;
}

double *minq(double **A,double *X,double *B, int s)
{
    double *Q;
    double *W;
    double *r;
    double t;
    Q = new double[s];
    r = new double[s];
    for(int k=0;k<50;k++)
    {
        r=rar(A,Q,B,s);
        t=tau(A,r,s);
        for(int i=0;i<s;i++)
        {
            Q[i]=Q[i]-t*r[i];
        }
    }
    return Q;
}

int main() {
    int s=5;
    double **A;
    double *B;
    double *X;
    A=new double*[s];
    B=new double[s];
    X=new double[s];
    for(int i=0;i<s;i++)
    {
        A[i]=new double[s];
    }
    A[0][0]=2;
    A[0][1]=1;
    B[0]=1;
    for(int i=1;i<s;i++)
    {
        A[i][i]=i*i+1;
        A[i][i+1]=1;
        A[i][i-1]=1;
        B[i]=i+1;
    }
    
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            cout<<A[i][j]<<' '<<flush;
        }
        cout<<endl;
    }
    for(int i=0;i<s;i++)
    {
        cout<<B[i]<<' '<<endl;
    }
    X=minq(A,X,B,s);
    for(int i=0;i<s;i++)
    {
        cout<<X[i]<<' '<<endl;
    }
}

