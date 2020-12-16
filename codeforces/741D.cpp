#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
vector<pair<int, int>> g[500005];
unordered_map<int, int> m[500005];
int r[500005];
const int L = 'v' - 'a';
void dfs(int u, int d, int mask){
    m[u][mask] = d;
    for(auto &vc : g[u]){
        int &v = vc.first;
        int &bm = vc.second;
        dfs(v, d + 1, mask ^ bm);
        if(m[u].size() < m[v].size()) swap(m[u], m[v]);
        for(auto &x: m[v]){
            if(m[u].count(x.first)) r[u] = max(r[u], x.second + m[u][x.first] - 2 * d);
            for(int i = 0; i <= L; i++){
                int w = x.first ^ (1 << i);
                if(m[u].count(w)) r[u] = max(r[u], x.second + m[u][w] - 2 * d);
            }
        }
        for(auto &x: m[v]){
            int &a = m[u][x.first];
            a = max(a, x.second);
        }
        r[u] = max(r[u], r[v]);
        m[v].clear();
    }
}

int main(){
    io_boost;
    cin >> n;
    char ev;
    for(int i = 1, v; i < n; i++){
        cin >> v >> ev;
        v--;
        g[v].push_back({i, 1 << (ev - 'a')});
    }
    dfs(0, 0, 0);
    for(int i = 0; i < n; i++) cout << r[i] << " ";
    cout << endl;
    return 0;
}