#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

# define n 6

double LSQ(double* X, double* F, int K, double x0, int N);
double Integral(double* X, double* F, int N);
double* Phi(double* X, double k, int N);
double ppphi(double x, double k);
double* Mult(double* X, double* Y, int N);
double* Gauss(double** A, double* B, int N);

int main()
{
    int N=6;
    double X[n]={0, 1, 2, 3, 4, 5};
    double F[n]={1, exp(1), exp(2), exp(3), exp(4), exp(5)};
    
    //double X[n]={0, 0.2, 0.4, 0.6, 0.8, 1};
    //double F[n]={1, exp(0.2), exp(0.4), exp(0.6), exp(0.8), exp(1)};
    double x0=3;
    int K=5;
    
    
    cout << LSQ(X, F, K, x0, N) << '\n';
}


double LSQ(double* X, double* F, int K, double x0, int N)
{
    double** A;
    A=new double* [K];
    for (int i=0; i<K; i++)
    {
        A[i]=new double [K];
    }
    
    double* B;
    B=new double [K];
    
    double* C;
    C=new double [K];
    
    for (int i=0; i<K; i++)
    {
        for (int j=0; j<K; j++)
        {
            A[i][j]=Integral(X, Mult(Phi(X,i,N), Phi(X,j,N), N), N);
        }
        B[i]=Integral(X, Mult(Phi(X,i,N), F, N), N);
    }

    C=Gauss(A,B,K);

    double sum=0;
    for (int i=0; i<K; i++)
    {
        sum+=C[i]*ppphi(x0, i);
    }
    
    return sum;
    
}


double Integral(double* X, double* F, int N)
{
    double I=0;
    
    for (int i=1; i<N; i++)
    {
        I+=(F[i]+F[i-1])/2*(X[i]-X[i-1]);
        
    }
    return I;
    
}


double* Phi(double* X, double k, int N)
{
    double* P;
    P=new double[N];
    
    for (int i=0; i<N; i++)
    {
        P[i]=pow(X[i],k);
    }
    
    return P;
    
}


double ppphi(double x, double k)
{
    return pow(x,k);
}


double* Mult(double* X, double* Y, int N)
{
    double* Z;
    Z=new double[N];
    
    for (int i=0; i<N; i++)
    {
        Z[i]=X[i]*Y[i];
    }
    
    return Z;
    
}

void print(double **M, int K)
{
    for (int i=0; i<K; i++)
    {
        for (int j=0; j<K+1; j++)
        {
            cout << M[i][j] << '\t';
        }
        cout << '\n';
    }
}

double* Gauss(double** A, double* B, int K)
{
    double** M;
    M=new double* [K];
    for (int i=0; i<K; i++)
    {
        M[i]=new double [K+1];
    }
    
    for (int i=0; i<K; i++)
    {
        for (int j=0; j<K; j++)
        {
            M[i][j]=A[i][j];
        }
        M[i][K]=B[i];
    }
    
    //print(M, K);
    
    double c;
    double* X;
    X=new double [K];
    
    for (int i=0; i<K-1; i++)
        {
            for (int j=i+1; j<K; j++)
            {
                c=M[j][i]/M[i][i];
                for (int k=0; k<K+1; k++)
                {
                    M[j][k]=M[j][k]-c*M[i][k];
                }
            }
        }
        
    for(int i=K-1; i>=0; i--)
    {
        X[i]=M[i][K];
        for (int j=i+1; j<K; j++)
        {
            X[i]=X[i]-M[i][j]*X[j];
        }
        X[i]=X[i]/M[i][i];
        
    }
    
    for (int i=0; i<K; i++)
    {
        //cout << X[i] <<'\n';
    }
    
    return X;
   
}








