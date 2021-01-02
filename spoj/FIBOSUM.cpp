#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


void multiply(vector<vector<ulli>> &m1, vector<vector<ulli>> &m2, vector<vector<ulli>> &res, ulli mod){
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

void matrix_power(vector<vector<ulli>> &m, ulli r, ulli mod){
    int N = m.size();
    vector<vector<ulli>> cur(N, vector<ulli>(N, 0));
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

ulli sum_fib(lli n, ulli mod){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    vector<vector<ulli>> init = {{1, 0, 1}}, m = {{1, 0, 0}, {1, 0, 1}, {1, 1, 1}}, res = {{0, 0, 0}};
    matrix_power(m, n - 1, mod);
    multiply(init, m, res, mod);
    return res[0][0];
}

int main(){
    io_boost
    int mod = 1000000007;
    int n, m, t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << ((sum_fib(m, mod) - sum_fib(n - 1, mod) + mod) % mod) << endl; 
    }
    
    return 0;
}