# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 2e5 + 5, oo = numeric_limits<int>::max(), MOD = 1e9 + 7;
int N, M;
vector<int> g[MAXN], gp[MAXN];

void bfs(int src, vector<int> &dist){
    queue<int> queue;
    bool visited[N] = {false};
    visited[src] = true;
    dist[src] = 0;
    queue.push(src);
    while(!queue.empty()){
        int u = queue.front();
        queue.pop();
        for(int v: g[u])
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                queue.push(v);
            }
    }
}

lli dp[MAXN];
lli go(int u){
    if(u == N - 1) return dp[u] = 1;
    if(dp[u] != -1) return dp[u];
    lli w = 0;
    for(int v: gp[u])
        w = (w + go(v)) % MOD;
    return dp[u] = w;
}

int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ds(N, oo), dt(N, oo);
    bfs(0, ds);
    bfs(N - 1, dt);
    if(ds[N - 1] == oo){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++)
        for(int j : g[i])
            if((ds[i] + dt[j] + 1) == ds[N - 1]){
                gp[i].push_back(j);
            }
    memset(dp, -1, sizeof(dp));
    cout << go(0) << endl;
    return 0;
}