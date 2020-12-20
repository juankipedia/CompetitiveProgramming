#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int MAXN = 1000;

int t, N, M, q, ans[1000];
vector<int> g[MAXN];
set<int> s[MAXN];

void dfs(int u, int p){
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, u);
        if(s[v].size() > s[u].size()) swap(s[v], s[u]);
        for(int q: s[v]){
            if(s[u].count(q)){
                ans[q] = u;
                s[u].erase(q);
            }
            else s[u].insert(q);
        }
    }
}

int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> N;
        for(int i = 0; i < N; i++) g[i] = {}, s[i].clear();
        for(int i = 0, n; i < N; i++){
            cin >> n;
            for(int j = 0, v; j < n; j++){
                cin >> v;
                v--;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }
        cin >> q;
        for(int i = 0, u, v; i < q; i++){
            cin >> u >> v;
            u--; v--;
            if(u == v){
                ans[i] = u;
                continue;
            }
            s[u].insert(i);
            s[v].insert(i);
        }
        dfs(0, 0);
        cout << "Case " << ti << ":" << endl;
        for(int i = 0; i < q; i++) cout << ans[i] + 1 << endl;
    }   
    return 0;
}