/*
    Articulation points
*/
const int MAXN = 20000;
int n, m, t, ans, disc[MAXN], low[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p){
    vis[u] = true;
    low[u] = disc[u] = ++t;
    bool has_back_edge = 0;
    int children = 0;
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(p != -1 && low[v] >= disc[u]) has_back_edge = 1;\
            children++;
        }
        else if(v != p) low[u] = min(low[u], disc[v]);
    }
    if(has_back_edge) ans++;
    if(p == -1 && children > 1) ans++;
}


/*
    Bridges
*/
int n, m, q, t;
const int MAXN = 1e5 + 5;
bool vis[MAXN];
int disc[MAXN], low[MAXN], comp[MAXN];

vector<int> g[MAXN];
vector<pair<int, int>> bridge;
void dfs(int u, int p){
    vis[u] = 1; 
    disc[u] = low[u] = ++t;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v, u);
            low[u]  = min(low[u], low[v]);
            if(low[v] > disc[u]) bridge.push_back({u, v});
        }
        else if(v != p) low[u]  = min(low[u], disc[v]);
    }
}
