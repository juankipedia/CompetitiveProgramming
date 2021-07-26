# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

# define U(t) t.second.first
# define V(t) t.second.second
# define W(t) t.first
typedef pair<lli, pair<int, int>> edge; 

const int MAXM = 4020025, MAXN = 2005;
edge edges[MAXM], mst[MAXN];
int N, M, p_set[MAXN];

void build(){
    for(int i = 0; i < N; i++) p_set[i] = i;
}

int find(int a){
    if(p_set[a] != a) p_set[a] = find(p_set[a]);
    return p_set[a];
}

void join(int a, int b){
    p_set[find(a)] = find(b);
}

void kruskal(){
    sort(edges, edges + M);
    build();
    int i = 0;
    for(int e = 0; i < N - 1;){
        int u = find(U(edges[e])), v = find(V(edges[e]));
        if(u != v){
            join(u, v);
            mst[i++] = edges[e];
        }
        e++;
    }
}

int d[MAXN][MAXN], df[MAXN][MAXN];
vector<pair<int, int>> g[MAXN];

void dfs(int u, int td, int p, vector<int> & dist){
    dist[u] = td;
    for(auto &[d, v]: g[u]){
        if(v == p) continue;
        dfs(v, td + d, u, dist);
    }
}

int main(){
    io_boost;
    cin >> N;
    bool f = true;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> d[i][j];
            if(i == j && d[i][j]) f = false;
            else if(i != j && d[i][j]) edges[M++] = {d[i][j], {i, j}};
            else if(i != j) f = false;
        }

    if(!f){
        cout << "NO" << endl;
        return 0;
    }
    kruskal();
    for(int i = 0; i < N - 1; i++){
        auto &[d, p] = mst[i];
        auto &[u, v] = p;
        g[u].push_back({d, v});
        g[v].push_back({d, u});
    }

    for(int i = 0; i < N; i++){
        vector<int> dist(N, 0);
        dfs(i, 0, -1, dist);
        for(int j = 0; j < N; j++) df[i][j] = dist[j];
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(df[i][j] != d[i][j]){
                f = false;
                break;
            }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}