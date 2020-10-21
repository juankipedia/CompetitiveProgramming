#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, U, V, d[10000], l[10000], p[10000], t, c;
bool visited[10000];
vector<int> g[10000];

void count_cut_vertices(int u){
    visited[u] = true;
    l[u] = d[u] = ++t;
    bool has_back_edge = false;
    for(int v: g[u]){
        if(!visited[v]){
            p[v] = u;
            count_cut_vertices(v);
            l[u] = min(l[u], l[v]);
            if(p[u] != -1 && l[v] >= d[u])
                has_back_edge = true;
        }
        else if(v != p[u]) l[u] = min(l[u], d[v]);
    }
    if(has_back_edge) c++;
}

int main(){
    io_boost;
    while(cin >> n >> m && n != 0){
        for(int i = 0; i < n; i++){
            g[i].clear();
            visited[i] = false;
            d[i] = -1;
            l[i] = -1;
            p[i] = -1;
        }
        for(int i = 0; i < m; i++){
            cin >> U >> V;
            U--; V--;
            g[U].push_back(V);
            g[V].push_back(U);
        }
        t = 0;
        c = 0;
        for(int i = 0; i < n; i++)
            count_cut_vertices(i);
        cout << c << endl;
    }
    
    return 0;
}