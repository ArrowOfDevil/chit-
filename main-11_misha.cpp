//
//  main.cpp
//  zad 11
//
//  Created by Михаил Смакотин on 23.03.2024.
//

#include <iostream>


using namespace std;

void progon(double **A,double *X, double *B, int s)
{
    double *ksi;
    double *eta;
    ksi=new double[s+1];
    eta=new double[s+1];
    ksi[0]=0;
    eta[0]=0;
    ksi[1]=-A[0][1]/A[0][0];
    eta[1]=B[0]/A[0][0];
    cout<<ksi[1]<<' '<<eta[1]<<endl;
    for(int i=2;i<(s+1);i++)
    {
        ksi[i]=-A[i-1][i]/(A[i-1][i-1]+A[i-1][i-2]*ksi[i-1]);
        eta[i]=(-A[i-1][i-2]*eta[i-1]+B[i-1])/(A[i-1][i-1]+A[i-1][i-2]*ksi[i-1]);
        cout<<ksi[i]<<' '<<eta[i]<<endl;
    }
    X[s-1]=eta[s];
    for(int i=(s-2);i>=0;i--)
    {
        X[i]=ksi[i+1]*X[i+1]+eta[i+1];
    }
    
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
    progon(A, X, B, s);
    for(int i=0;i<s;i++)
    {
        cout<<X[i]<<' '<<endl;
    }
}
