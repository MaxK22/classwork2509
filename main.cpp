#include <iostream>
#include "vector"
#include "matrix.h"
using namespace std;

vector<vector<double> > RandomMatrix(int n, int m)
{
    vector< vector<double> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i].push_back(rand()%100);
    return res;
}

int main() {
    Matrix<double> a(RandomMatrix(4, 4));
    //Matrix<int> b(RandomMatrix(4, 4));
    cout << a << endl;
    try
    {
        //cout << "" << (a*b) << endl;
        cout << "Gause: \n" << (a.Gause()) << endl;
        //cout << "x = A-1 * b = : \n" << (Matrix<double>(a.inverse) * (Matrix<double>(a.Data(), a.columns()-1)));
    }
    catch (const char* msg)
    {
        cerr << "Exception caught: " << msg << endl;
    }
    return 0;
}
