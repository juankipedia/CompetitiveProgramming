# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 200005;
int n, m;
vector<int> g[MAXN];
bool visited[MAXN];
set<int> s;

void dfs(int u){
    visited[u] = true;
    for(int v : g[u])
        if(!visited[v] && !s.count(v))
            cout << u + 1 << " " << v + 1 << endl,
            dfs(v);
}

int main(){
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = 0;
    for(int i = 0; i < n; i++)
        if(g[i].size() > g[root].size()) root = i;
    for(int v : g[root]) s.insert(v);
    s.insert(root);
    for(int v : g[root]){
        cout << root + 1 << " " << v + 1 << endl;
        dfs(v);
    }
    dfs(root);
    return 0;
}