#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

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

int main(){
    io_boost;
    matrix init(26, vector<ulli>(26, 0));
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            cin >> init[i][j];
    cin >> t;
    matrix m(26, vector<ulli>(26, 0)), m2(26, vector<ulli>(26, 0)), vec(1, vector<ulli>(26, 1)), res(1, vector<ulli>(26, 0));
    ulli n, mod = 1000000007, cur = 1, ans[t] = {0};
    pair<ulli, pair<string, int>> q[t];
    for(int i = 0; i < t; i++) cin >> q[i].second.first >> q[i].first, q[i].second.second = i;
    sort(q, q + t);
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            m[i][j] = init[i][j];
    for(int i = 0; i < t; i++){
        q[i].first--;
        if(cur < q[i].first){
            for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) m2[i][j] = init[i][j];
            matrix_power(m2, q[i].first - cur, mod);
            multiply(m, m2, m, mod);
        }
        multiply(vec, m, res, mod);
        ans[q[i].second.second] = res[0][q[i].second.first[0] - 'a'];
        cur = q[i].first;
    }
    for(int i = 0; i < t; i++) cout << ans[i] << endl;
    return 0;
}