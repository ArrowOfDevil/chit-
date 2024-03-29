//
//  main.cpp
//  zad 10
//
//  Created by Михаил Смакотин on 23.03.2024.
//

#include <iostream>

using namespace std;

void gauss(double **A,double *X, double *B, int s)
{
    double **Q;
    double t;
    Q=new double*[s];
    for(int i=0;i<s;i++)
    {
        Q[i]=new double[s+1];
    }
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            Q[i][j]=A[i][j];
        }
        Q[i][s]=B[i];
    }
    for(int q=1;q<s;q++)
    {
        for(int i=q;i<s;i++)
        {
            t=Q[i][q-1]/Q[q-1][q-1];
            for(int j=0;j<(s+1);j++)
            {
                Q[i][j]=Q[i][j]-Q[q-1][j]*t;
                if(fabs(Q[i][j])<1e-15){
                    Q[i][j]=0;
                }
            }
        }
    }
    
    for(int q=(s-1);q>0;q--)
    {
        for(int i=(q-1);i>=0;i--)
        {
            t=Q[i][q]/Q[q][q];
            for(int j=0;j<(s+1);j++)
            {
                Q[i][j]=Q[i][j]-Q[q][j]*t;
                if(fabs(Q[i][j])<1e-15)
                {
                    Q[i][j]=0;
                }
                }
            }
        }
    
    
    
    for(int i=0;i<s;i++)
    {
        X[i]=Q[i][s]/Q[i][i];
    }
    
}


int main(){
    int s=3;
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
    A[0][0]=3;
    A[0][1]=2;
    A[0][2]=-5;
    A[1][0]=2;
    A[1][1]=-1;
    A[1][2]=3;
    A[2][0]=1;
    A[2][1]=2;
    A[2][2]=-1;
    B[0]=-1;
    B[1]=13;
    B[2]=9;
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
    gauss(A, X, B, s);
    for(int i=0;i<s;i++)
    {
        cout<<X[i]<<' '<<endl;
    }
    return 0;
}
