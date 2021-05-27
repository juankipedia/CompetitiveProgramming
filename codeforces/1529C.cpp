# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int t, n, rl[MAXN][2];
vector<int> g[MAXN];
lli dp[MAXN][2];

lli go(int u, int p, int last){
    lli mini = 0, maxi = 0;
    
    if(dp[u][last] != -1) return dp[u][last];

    if(p != -1){
        mini += abs(rl[u][0] - rl[p][last]);
        maxi += abs(rl[u][1] - rl[p][last]);
    }
    for(int v : g[u]){
        if(v == p) continue;
        mini += go(v, u, 0);
        maxi += go(v, u, 1);
    }
    return dp[u][last] = max(mini, maxi);
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> rl[i][0] >> rl[i][1];
            g[i].clear();
            dp[i][0] = dp[i][1] = -1;
        }
        for(int i = 0, u, v; i < n - 1; i++){
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << go(0, -1, 0) << endl;
    }
    return 0;
}