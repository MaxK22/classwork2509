#include <iostream>
#include <fstream>
#include "algorithm"
#include "vector"
#include "matrix.h"
using namespace std;

vector<vector<double> > RandomMatrix(int n, int m)
{
    vector< vector<double> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i].push_back(double (rand()%100));
    return res;
}

vector<double> dline(vector<double> a, vector<double> b, double k)
{
    vector<double> res;
    for(int i = 0; i < a.size(); ++i)
        res.push_back(a[i] - b[i] * k);
    return res;
}

string MetodGause(Matrix<double> a)
{
    int n = a.rows(), m = a.columns();
    vector< vector<double> > res(n);
    res = a.Data();
    for (int j = 0; j < min(n,m - 1); ++j) {
        for (int k = j + 1; k < n && res[j][j] == 0; ++k)
            if(res[k][j] != 0) res[j] = dline(res[j], res[k], -1);
        for (int k = j + 1; k < n && res[j][j] != 0; ++k) {
            if (res[k][j] != 0) {
                double p = res[k][j] / res[j][j];
                res[k] = dline(res[k], res[j], p);
            }
        }
    }
    string answer;
    for(int i = n - 1; i >= 0; --i)
    {
        if(i > m - 1 && res[i][m-1] != 0)
        {
            answer = "System is inconsisten";
            i = -1;
        }
        else if(i == m-1)
        {
            answer = res[i][m-1];
        }
    }


    return answer;
}

int main() {
    ifstream input;
    input.open("input.txt");
    int s;
    input >> s;
    for(int i = 0; i < s; ++i)
    {
        int n, m;
        input >> n >> m;
        vector<vector<double>> vect(n);
        double x;
        m++;
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < m; ++k)
            {
                input >> x;
                vect[j].push_back(x);
            }
        }
        Matrix<double> a(vect);
        cout << "Case #" << i + 1 << ":\n" << MetodGause(a) << endl;
    }
    input.close();
    return 0;
}
