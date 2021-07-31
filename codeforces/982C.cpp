# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int n, ans, s[100005];
vector<int> g[100005];

int dfs(int u, int p){
    s[u] = 1;
    for(int v: g[u]){
        if(v == p) continue;
        s[u] += dfs(v, u);
    }
    if(p != -1 && s[u] % 2 == 0 && (n - s[u]) % 2 == 0) ans ++;
    return s[u];
}


int main(){
    cin >> n;
    for(int i = 0, u, v; i < n - 1; i++) 
        cin >> u >> v, 
        u--, v--,
        g[u].push_back(v),
        g[v].push_back(u);
    dfs(0, -1);
    if(ans == 0 && n % 2) cout << -1 << endl;
    else cout << ans << endl; 
    return 0;
}