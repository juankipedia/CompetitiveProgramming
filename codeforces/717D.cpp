# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
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
            for(int j = 0; j < o.M; j++){
                for(int k = 0; k < M; k++) r.m[i][j] += (m[i][k] * o.m[k][j]);
            }
        return r;
    }
};
 
template<class T> Matrix<T> fpow(Matrix<T> M, ulli r){
    Matrix<T> ans(true, M.N, M.N);
    for(; r; M = M * M, r >>= 1)
        if(r & 1) ans = ans * M;
    return ans;
}
 
int n, x;
double P[200];
 
int main(){
    scanf("%d %d", &n, &x);
    x++;
    Matrix<double> p(false, 200, 200), dp(false, 200, 1);
    for(int i = 0; i < x; i++) scanf("%lf", &P[i]);
    for(int i = 0; i < 128; i++){
        for(int j = 0; j < 128; j++) 
            p.m[i][j] = P[i ^ j];
        dp.m[i][0] = i == 0 ? 1 : 0;
    }
    auto ans = fpow(p, n);
    printf("%.13lf\n", (double)(1) - ans.m[0][0]);
    return 0;
}