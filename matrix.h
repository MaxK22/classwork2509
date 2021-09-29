#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename T>
class Matrix
{
    int n;
    int m;
    vector< vector<T> > data;
public:
    Matrix(vector< vector<T> >);
    Matrix(int n_);
    Matrix(int n_, int m_);
    int rows() const { return n; };
    int columns() const { return m; };
    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(const Matrix&) const;
    const Matrix operator^(int) const;
    const Matrix operator*(T) const;
    const Matrix transparent();
    vector<T>& operator[](int i) { return data[i]; };
    const vector<T>& operator[](int i) const { return data[i]; };
    template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, const Matrix<Type>&);
};

template<typename T>
Matrix<T>::Matrix(vector< vector<T> > vect)
{
    data = vect;
    n = vect.size();
    m = vect[0].size();
}

template<typename T>
Matrix<T>::Matrix(int n_)
{
    n = n_;
    m = n_;
    vector<T> x;
    x.assign(m, 0);
    data.assign(n, x);
}

template<typename T>
Matrix<T>::Matrix(int n_, int m_)
{
    n = n_;
    m = m_;
    vector<T> x;
    x.assign(m, 0);
    data.assign(n, x);
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& a) const
{
    if (a.rows() != n || a.columns() != m)
        throw "Matrices have different sizes";
    vector< vector<T> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i].push_back(data[i][j] + a[i][j]);
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(T k) const
{
    vector< vector<T> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[i].push_back(data[i][j] * k);
    return Matrix(res);
}

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& a)
{
    for (int i = 0; i < a.rows(); ++i)
    {
        for (int j = 0; j < a.columns(); ++j)
            out << a[i][j] << " ";
        out << endl;
    }
    return out;
}

template<typename T>
istream &operator>>(istream& in, Matrix<T>& a) {
    for (int i = 0; i < a.rows(); ++i)
        for (int j = 0; j < a.columns(); ++j)
            in >> a[i][j];
    return in;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix& a) const
{
    if (a.rows() != m)
        throw "Matrices haven't match sizes";
    vector< vector<T> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a.columns(); ++j) {
            res[i].push_back(0);
            for (int l = 0; l < m; ++l)
                res[i][j] += data[i][l] * a[l][j];
        }
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::transparent()
{
    vector< vector<T> > res(m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            res[i].push_back(data[j][i]);
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::operator^(int k) const
{
    if (n != m)
        throw "Matrix hasn't match sizes";
    vector< vector<T> > res = data;
    for(int i = 1; i < k; ++i)
        res = res * data;
    return Matrix(res);
}
#endif //UNTITLED_MATRIX_H
