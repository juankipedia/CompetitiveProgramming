#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100005;
int N, C, M;
vector<int> g[MAXN];
bool cheese[MAXN];
int m[MAXN];
bool visited[MAXN], getn[MAXN];

void solve(int u, bool mini){
    int in = cheese[u] ? 1 : 0;
    if(u == N - 1){
        m[u] = in;
        getn[u] = true;
        return;
    }
    if(visited[u]) return;
    visited[u] = true;
    
    if(mini) m[u] = MAXN;
    else m[u] = 0;

    for(int v: g[u]){
        solve(v, mini);
        if(mini){
            if(getn[v])
                m[u] = min(m[u], in + m[v]);
        }
        else{
            if(getn[v])
            m[u] = max(m[u], in + m[v]);
        }
        getn[u] = getn[u] || getn[v]; 
    }
   
    return;
}

int main(){
    cin >> N >> C >> M;
    for(int i = 0, c; i < C; i++) cin >> c, cheese[--c] = true;
    for(int i = 0, u, v; i < M; i++) cin >> u >> v, g[--u].push_back(--v);
    memset(visited, false, sizeof(visited));
    memset(getn, false, sizeof(getn));
    solve(0, true);
    cout << m[0] << " ";
    memset(visited, false, sizeof(visited));
    memset(getn, false, sizeof(getn));
    solve(0, false);
    cout << m[0] << endl;
    return 0;
}