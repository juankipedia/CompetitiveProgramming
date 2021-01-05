#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
const lli MOD = 1000000007;
 
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
 
ulli sum_fib(lli n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    Matrix<ulli> init(false, 1, 3), m(false, 3, 3);
    init.m = {{1, 0, 1}}; m.m = {{1, 0, 0}, {1, 0, 1}, {1, 1, 1}};
    m = fpow(m, n - 1);
    return (init * m).m[0][0];
}
 
int main(){
    io_boost
    int mod = 1000000007;
    int n, m, t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << ((sum_fib(m) - sum_fib(n - 1) + mod) % mod) << endl; 
    }
    
    return 0;
} 