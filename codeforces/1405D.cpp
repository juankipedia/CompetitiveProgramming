#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a, b, da, db, u, v, diameter, x;
vector<int> g[100000];
int dist[100000];

void dfs(int node, int parent, int depth){
    depth++;
    for(const int &child : g[node]){
        if(child == parent) continue;
        dist[child] = depth;
        if(diameter < depth){
            diameter = depth;
            x = child;
        }
        dfs(child, node, depth);
    }
}

int main(){
    cin >> t;
    while (t--){
        cin >> n >> a >> b >> da >> db;
        a--; b--;
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        diameter = -1;
        dfs(a, -1, 0);
        int dab = dist[b];
        dfs(x, -1, 0);
        if(2 * da >= diameter) cout << "Alice\n";
        else if(2 * da >= db) cout << "Alice\n";
        else if(dab <= da) cout << "Alice\n";
        else cout << "Bob\n";
        for(int i = 0; i < n; i++) g[i].clear();
    }
    
    return 0;
}