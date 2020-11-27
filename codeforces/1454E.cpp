#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, u, v;
vector<int> g[200000];
bool inloop[200000], visited[200000], processed[200000];
int parent[200000], cnt[200000];

void mark_loop(int u, int p){
    if(visited[u]){
        int cur = p;
        inloop[u] = true;
        while(cur != u){
            inloop[cur] = true;
            cur = parent[cur];
        }
        return;
    }
    visited[u] = true;
    parent[u] = p;
    for(int v: g[u])
        if(!processed[v] && v != p) mark_loop(v, u);
    processed[u] = true;
}

int count(int u, int p){
    int c = 1;
    for(int v: g[u])
        if(v != p && !inloop[v]) c += count(v, u);
    return cnt[u] = c;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) g[i].clear();
        memset(visited, false, sizeof(visited));
        memset(inloop, false, sizeof(inloop));
        memset(processed, false, sizeof(processed));
        for(int i = 0; i < n; i++){
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        mark_loop(0, -1);
        lli ans = 0;
        for(int i = 0; i < n; i++){
            if(inloop[i]){
                lli c = count(i, -1);
                ans += (c * (c - 1) / 2) + c * (n - c);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}