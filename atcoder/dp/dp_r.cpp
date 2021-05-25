# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


const ulli MOD = 1e9 + 7;

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

lli N, K;

int main(){
    cin >> N >> K;
    Matrix<lli> m(false, N, N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> m.m[i][j];
    m = fpow(m, K);
    lli ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) ans = (ans + m.m[i][j]) % MOD;

    cout << ans << endl;
}