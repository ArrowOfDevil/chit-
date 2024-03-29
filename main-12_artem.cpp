#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

#define n 3

void MRA(double A[n][n], double F[n], double X0[n], double eps);
double dot(double V[n], double W[n]);

int main()
{
    double A[n][n]={{2, 6, 5}, {6, 3, 7}, {5, 7, 4}};
    double F[n]={29, 33, 31};
    double X0[n]={1, 1, 1};
    double eps=0.00001;
    
    MRA(A, F, X0, eps);
    
    return 0;
}


void MRA(double A[n][n], double F[n], double X0[n], double eps)
{
    double R[n]={0, 0, 0}, AX[n]={0, 0, 0}, AR[n]={0, 0, 0};
        
    double t=0, num=0;
    do
    {
        for (int i=0; i<n; i++)
        {
            AX[i]=0;
        }
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                AX[i]+=A[i][j]*X0[j];
            }
            R[i]=F[i]-AX[i];
        }
        
        for (int i=0; i<n; i++)
        {
            AR[i]=0;
        }
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                AR[i]+=A[i][j]*R[j];
            }
        }
        
        t=dot(AR,R)/dot(AR,AR);
        
        for (int i=0; i<n; i++)
        {
            X0[i]=X0[i]+t*R[i];
        }
         
        cout << sqrt(dot(R,R)) << '\n';
        num++;
        if (num == 100)
        {
            break;
        }
    }
    while (sqrt(dot(R,R))>eps);
    
    for(int i=0; i<n; i++)
    {
        cout << "X" << "(" << i+1 << ")" << "=" << X0[i] << '\n';
    }
}
    
    
double dot(double V[n], double W[n])
{
    double s=0;
    
    for (int i=0; i<n; i++)
    {
        s+=V[i]*W[i];
    }
    return s;
}
    
    
    
    
    
    
    
