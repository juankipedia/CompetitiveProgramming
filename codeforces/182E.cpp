# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MOD = 1e9 + 7, MAXN = 105, MAXL = 3005;
int N, L, a[MAXN], b[MAXN];
lli dp[MAXL][MAXN][2];

lli go(int l, int j, int ar){
    if(l == 0) return 1;
    if(dp[l][j][ar] != -1) return dp[l][j][ar];
    lli ans = 0;
    int len = a[j];
    if(ar) len = b[j];

    for(int i = 0; i < N; i++){
        if(i == j) continue;
        if(a[i] <= l && a[i] == len) ans = (ans + go(l - a[i], i, 1)) % MOD;
        if(a[i] != b[i] && b[i] == len && b[i] <= l) ans = (ans + go(l - b[i], i, 0)) % MOD;
    }
    return dp[l][j][ar] = ans;
}

int main(){
    io_boost;
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    memset(dp, -1, sizeof(dp));
    lli ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i] <= L) ans = (ans + go(L - a[i], i, 1)) % MOD;
        if(a[i] != b[i] && b[i] <= L) ans = (ans + go(L - b[i], i, 0)) % MOD;
    }
    cout << ans << endl;
    return 0;
}