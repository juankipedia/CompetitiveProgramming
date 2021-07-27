# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 150005;
int N, parent[MAXN];

void build(){
    for(int i = 0; i < N; i++) parent[i] = i;
}

int find(int a){
    if(parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

void join(int a, int b){
    parent[find(a)] = find(b); 
}

vector<int> g[MAXN];

int main(){
    int m;
    cin >> N >> m;
    build();
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v; 
        u--; v--;
        g[u].push_back(v); 
        g[v].push_back(u);
        join(u, v);
    }
    map<int, set<int>> components;
    for(int i = 0; i < N; i++) components[find(i)].insert(i);
    bool ok = true;
    for(auto &[p, c] : components){
        for(int e: c){
            if(g[e].size() != (c.size() - 1)) ok = false;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}