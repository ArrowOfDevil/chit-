//
//  main.cpp
//  N11
//
//  Created by Александр Смакотин on 25.03.2024.
//

#include <iostream>
#include <math.h>

using namespace std;

vector<double> Gauss_3(vector<vector<double>>& A, vector<double>& B){
    
    int s = A.size();
    vector<double> ksi(s+1);
    vector<double> eta(s+1);
    vector<double> X(s);
    
    ksi[0]=0;
    eta[0]=0;
    ksi[1]=-A[0][1]/A[0][0];
    eta[1]=B[0]/A[0][0];
    for(int i=2;i<(s+1);i++)
    {
        ksi[i]=-A[i-1][i]/(A[i-1][i-1]+A[i-1][i-2]*ksi[i-1]);
        eta[i]=(-A[i-1][i-2]*eta[i-1]+B[i-1])/(A[i-1][i-1]+A[i-1][i-2]*ksi[i-1]);
        
    }
    
    X[s-1]=eta[s];
    for(int i=(s-2);i>=0;i--)
    {
        X[i]=ksi[i+1]*X[i+1]+eta[i+1];
    }
    
    return X;
}


int main(int argc, const char * argv[]) {
    
    int s = 5;
    vector<vector<double>> A{{2,1,0,0,0}, {1,2,1,0,0},{0,1,5,1,0},{0,0,1,10,1},{0,0,0,1,17}};
    vector<double> B{1,2,3,4,5};
    vector<double> X;
    
    
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
    
    X = Gauss_3(A, B);
    
    for(int i=0;i<s;i++)
    {
        cout<<X[i]<<' '<<endl;
    }
}

