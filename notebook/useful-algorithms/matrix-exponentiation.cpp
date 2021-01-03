#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * MATRIX EXPONENTIATION.
 * This file provides a fast way of calculating m^r, where m is a NxN square matrix
 * Time complexity: O(N^ 3 * log(r))
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

typedef vector<vector<ulli>> matrix;

void multiply(matrix &m1, matrix &m2, matrix &res, ulli mod){
    int N = m1.size(), K = m1[0].size(), M = m2[0].size();
    ulli a[N][K], b[K][M];
    for(int i = 0; i < N; i++) for(int j = 0; j < K; j++) a[i][j] = m1[i][j];
    for(int i = 0; i < K; i++) for(int j = 0; j < M; j++) b[i][j] = m2[i][j];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ulli val = 0;
            for(int k = 0; k < K; k++) val = (val % mod + (a[i][k] % mod * b[k][j] % mod) % mod) % mod;
            res[i][j] = val;
        }
    }
}

void matrix_power(matrix &m, ulli r, ulli mod){
    int N = m.size();
    matrix cur(N, vector<ulli>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cur[i][j] = m[i][j];
            if(i == j) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
    while(r > 0){
        if(r % 2 == 1) multiply(m, cur, m, mod);
        multiply(cur, cur, cur, mod);
        r /= 2;
    }
}

ulli fibonacci(ulli n, ulli mod){
    if(n == 0) return 0;
    if(n == 1) return 1;
    matrix init = {{0, 1}}, m = {{0, 1}, {1, 1}}, res = {{0, 0}};
    matrix_power(m, n - 1, mod);
    multiply(init, m, res, mod);
    return res[0][1];
}