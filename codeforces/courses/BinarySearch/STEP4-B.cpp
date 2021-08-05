# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef long double ld;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 1e5 + 5;
int n, m;
vector<pair<int, ld>> g[MAXN];
ld x;
vector<ld> dp;
vector<bool> dpb;

ld dfs(int u){
    if(u == n - 1) return dp[u] = 0;
    if(dpb[u]) return dp[u];
    dpb[u] = true;
    ld ans = 1e10;
    for(auto &[v, c] : g[u])
        ans = min(ans, c - x + dfs(v));
    return dp[u] = ans;
}

vector<int> ans;
void dfs_(int u){
    
    ans.push_back(u + 1);
    for(auto &[v, c] : g[u]){
        if(abs(dp[v] - (dp[u] - (c - x))) <= 1e-10){
            dfs_(v);
            return;
        }
    }
}

bool check(){
    dpb.assign(n + 5, false);
    return dfs(0) <= 0.0;
}

int main(){
    cin >> n >> m;
    dp.assign(n + 5, 0);
    dpb.assign(n + 5, false);
    for(int i = 0, u, v; i < m; i++){
        ld c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].push_back({v, c});
    }
    ld lo = 0, hi = 100;
    for(int i = 0; i < 100; i++){
        x = (lo + hi) / 2;
        if(check()) hi = x;
        else lo = x;
    }
    x = lo;
    dfs(0);
    dfs_(0);
    cout << ans.size() - 1 << endl;
    for(int u: ans) cout << u << " ";
    cout << endl;
    return 0;
}