#include <iostream>
#include "vector"
#include "matrix.h"
using namespace std;

vector<vector<int> > RandomMatrix(int n, int m)
{
    vector< vector<int> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i].push_back(rand()%10);
    return res;
}

int main() {
    Matrix<int> a(RandomMatrix(4, 4));
    Matrix<int> b(RandomMatrix(4, 4));
    cout << a << endl << b << endl;
    try
    {
        cout << "" << (a*b) << endl;
    }
    catch (const char* msg)
    {
        cerr << "Exception caught: " << msg << endl;
    }
    return 0;
}
