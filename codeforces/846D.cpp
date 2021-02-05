#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 500 + 5, LOG2N = 9;;

int n, m, k, q;
int S[MAXN][MAXN], M[MAXN][MAXN];


int lg2[MAXN + 1], st[MAXN][MAXN][LOG2N + 1];

void build(int a[], int st[][LOG2N + 1]){
    int N = m + 1;
    lg2[1] = 0;
    for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < N; i++) st[i][0] = a[i];
    for(int j = 1; j <= LOG2N; j++)
        for(int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int maximun(int L, int R, int st[][LOG2N + 1]){
    int lg = lg2[R - L + 1];
    return max(st[L][lg], st[R - (1 << lg) + 1][lg]);
}



int main(){
    io_boost;
    cin >> n >> m >> k >> q;
    for(int i = 0, x, y; i < q; i++){
        cin >> x >> y;
        cin >> M[x][y];
        S[x][y] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            S[i][j] += S[i][j - 1];
        build(M[i], st[i]);
    }
    int ans = 1e9 + 5;
    for(int i = 1; (i + k - 1) <= n; i++){
        for(int j = k; j <= m; j++){
            if(S[i][j] - S[i][j - k] == k){
                //cout << j << " " << j - k + 1 << endl;
                int maxi = maximun(j - k + 1, j, st[i]);
                bool ok = true;
                for(int l = 1; l < k; l++){
                    if(S[i + l][j] - S[i + l][j - k] == k)
                        maxi = max(maximun(j - k + 1, j, st[i + l]), maxi);
                    else{
                        ok = false;
                        break;
                    }
                }
                if(ok) ans = min(ans, maxi);
            }
        }
    }
    if(ans != 1e9 + 5) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}