#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * MATRIX EXPONENTIATION.
 * This file provides a fast way of calculating m^r, where m is a NxN square matrix
 * Time complexity: O(N^3 * log(r))
 * 
 * USAGE:
 * We can calculate linear dps (such as fibonacci) by using this technique, 
 * this technique is useful when n is too big.
 * This file includes the example of calculating fibonacci of n by calculating:
 * 
 * res = init * m ^ (n - 1)
 * 
 * where init = {{0, 1}} and m = m = {{0, 1}, {1, 1}}, finally fibonacci(n) = res[0][1]
 * 
 **/

const ulli MOD = 1e5 + 7;

template<class T> struct Matrix{
    vector<vector<T>> m;
    int N, M;
    Matrix(bool identity, int rows, int columns){
        N = rows; M = columns;
        m.resize(N, vector<T>(M, 0));
        if(identity && N == M)
            for(int i = 0; i < N; i++) m[i][i] = 1;
    }
    Matrix operator * (const Matrix &o){
        Matrix<T> r(false, N, o.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < o.M; j++)
                for(int k = 0; k < M; k++) r.m[i][j] = (r.m[i][j] + (m[i][k] % MOD * o.m[k][j] % MOD) % MOD) % MOD;
        return r;
    }
};

template<class T> Matrix<T> fpow(Matrix<T> M, ulli r){
    Matrix<T> ans(true, M.N, M.N);
    for(; r; M = M * M, r >>= 1)
        if(r & 1) ans = ans * M;
    return ans;
}

ulli fibonacci(ulli n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    Matrix<ulli> I(false, 1, 2), M(false, 2, 2); 
    I.m = {{0, 1}};
    M.m = {{0, 1}, {1, 1}};
    M = fpow(M, n - 1);
    return (I * M).m[0][1];
}