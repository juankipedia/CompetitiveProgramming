# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int N;
vector<int> g[MAXN];
lli dp[MAXN][2];

lli go(int u, int p, int lc){
    if(dp[u][lc] != -1) return dp[u][lc];
    
    lli answ = 1, ansb = 1;
    bool f = false, fb = false;
    for(int v : g[u]){
        if(v == p) continue;
        f = true;
        answ = (answ * go(v, u, 0)) % MOD;
        if(lc != 1)
            ansb = (ansb * go(v, u, 1)) % MOD, fb = true;
    }
    lli ans = answ;
    if(fb) ans = (ans + ansb) % MOD;

    if(!f){
        if(lc == 1) ans = 1;
        else ans = 2;
    }
    return  dp[u][lc] = ans;
}

int main(){
    cin >> N;
    for(int i = 0, xi, yi; i < N - 1; i++){
        cin >> xi >> yi;
        xi--;
        yi--;
        g[xi].push_back(yi);
        g[yi].push_back(xi);
    }
    memset(dp, -1, sizeof(dp));
    
    cout << go(0, -1, 0) << endl;
    // for(int i = 0; i < N; i++){
    //     cout << "FORMAS DE PINTAR " << i + 1 << "CON lc " << 0 << endl;
    //     cout << dp[i][0] << endl;
    //     cout << "FORMAS DE PINTAR " << i + 1 << "CON lc " << 1 << endl;
    //     cout << dp[i][1] << endl;
    // }
    return 0;
}