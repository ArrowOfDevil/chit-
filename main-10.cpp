//
//  main.cpp
//  N10
//
//  Created by Александр Смакотин on 24.03.2024.
//

#include <iostream>
#include <vector>

using namespace std;

vector<double> gaussMethod(vector<vector<double>>& A, vector<double>& b){
    
    int n = A.size();
    vector<double> x(n);
    
    //прямой ход
    for (int i=0; i<n ; ++i) {
        for (int j=i+1; j<n; ++j) {
            double ratio = A[j][i]/A[i][i];
            for (int k=i; k<n; ++k) {
                A[j][k] -= ratio*A[j][k];
            }
            b[j]-=ratio*b[i];
        }
    }
    
    //обратный ход
    for(int i=n-1; i>=0; --i){
        x[i] = b[i];
        for(int j=i+1; j<n; ++j) x[i] -= A[i][j]*x[j];
        x[i] /= A[i][i];
    }
    
    return x;
    
}

int main(int argc, const char * argv[]) {
    vector<vector<double>> A = {{2,1},{3,2}};
    vector<double> B = {1,1};
    vector<double> answer = gaussMethod(A, B);
    
    return 0;
}
