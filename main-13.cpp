#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n)
{
    // single line to find factorial
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

double Neuton(vector<double>& x, vector<double>& y, double a) {
    int n = x.size();
    double sum = 0;
    double mult;
    vector<vector<double>> table(n, vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }
      
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            table[i][j] = j*(table[i][j - 1] - table[i+1][j - 1]) / (x[i] - x[i+j]);
        }
    }
    
    for(int k=0; k<n;k++){
        mult = 1;
        for(int i=0; i<k; i++){
            mult*=(a-x[i]);
        }
        sum = sum + (mult*table[0][k])/factorial(k);
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    
    vector<double> U{2,4,4,3,1,3,4,2};
    vector<double> X{5,3,2,6,1,7,8,9};
    cout<<Neuton(X, U, 4.0);
    return 0;
}
