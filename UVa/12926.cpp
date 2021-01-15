#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 5000;
int N, T, D, component[MAXN], cur_component;
bool g[MAXN][MAXN], gt[MAXN][MAXN];


stack<int> s;
bool visited[MAXN];

void dfs(bool g[][MAXN], int u, bool save){
    visited[u] = true;
    if(!save) component[u] = cur_component;
    for(int v = 0; v < N; v++)
        if(g[u][v] && !visited[v]) 
            dfs(g, v, save);
    if(save) s.push(u);
}

void kosaraju(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++)
        if(!visited[i])
            dfs(g, i, true);
    memset(visited, false, sizeof(visited));
    cur_component = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            dfs(gt, u, false);
            cur_component++;
        }
    }
}

int main(){
    while(cin >> N >> T){
        memset(g, true, sizeof(g));
        memset(gt, false, sizeof(gt));
        for(int i = 0; i < N; i++)
            g[i][i] = false;
        for(int i = 0, u, v; i < T; i++)
            cin >> u >> v, g[--u][--v] = false; 
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(g[i][j]) gt[j][i] = true;
        cin >> D;
        kosaraju();
        cout << cur_component * D << endl;
    }
    
    return 0;
}