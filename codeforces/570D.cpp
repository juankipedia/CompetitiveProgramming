#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m;
vector<int> g[500000];
vector<pair<int, int>> queries;
map<int, bool> q[500000];
string val;
map<int, map<char, int>> f[500000];

bool check(int v, int h){
    bool odd = false;
    for(auto &x: f[v][h])
        if(x.second % 2 && !odd) odd = true;
        else if(x.second % 2 && odd) return false;
    return true;
}

void dfs(int u, int p, int h){
    f[u][h][val[u]] = 1;
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, u, h + 1);
        if(f[v].size() > f[u].size()) swap(f[v], f[u]);
        for(auto &x: f[v]) 
            for(auto &y: x.second)
                f[u][x.first][y.first] += y.second;
        f[v].clear();
    }
    for(auto &query: q[u])
        query.second = check(u, query.first);
}

int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 1, p; i < n; i++){
        cin >> p;
        p--;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    cin >> val;
    for(int i = 0, v, h; i < m; i++){
        cin >> v >> h;
        v--;
        q[v][h] = false;
        queries.push_back({v, h});
    }

    dfs(0, -1, 1);

    for(auto &query: queries)
        if(q[query.first][query.second]) cout << "Yes" << endl;
        else cout << "No" << endl;

    return 0;
}