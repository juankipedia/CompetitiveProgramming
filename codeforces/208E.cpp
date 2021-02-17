#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100005, MAXM = 100005, LOG2N = 17;
vector<int> g[MAXN];

// EULER TOUR and LCA.

int a[2 * MAXN], up[MAXN][LOG2N + 5], dist[MAXN], N, M, in[MAXN], out[MAXN], t = 0;

void dfs(int u, int p, int h){
    a[t] = u;
    in[u] = t;
    t++;
    dist[u] = h;
    up[u][0] = p;
    for(int i = 1; i <= LOG2N; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for(int v: g[u])
        if(v != p) dfs(v, u, h + 1);
    a[t] = u;
    out[u] = t;
    t++;
}
 
int lca(int v, int p){
    for(int i = 0; i <= LOG2N; i++)
        if(p & (1 << i)) v = up[v][i];
    return v;
}

// MO's ALGORITHM

struct Query{
    int l, r, idx, v;
    bool p;
};
Query queries[MAXM];

int BLOCK_SIZE, l, r, freq[2 * MAXN], ans[MAXM], cnt[MAXN];
 
bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}

void add(int i){
    if(in[a[i]] == i) freq[dist[a[i]]]++;
}

void del(int i){
    if(in[a[i]] == i) freq[dist[a[i]]]--;
}
 
int get_ans(int v){
    return freq[dist[v]] - 1;
}
 
void mos(){
    BLOCK_SIZE = sqrt(t);
    sort(queries, queries + M, cmp);
    l = 1;
    r = 0;
    for(int i = 0; i < M; i++){
        if(queries[i].p){
            ans[queries[i].idx] = 0;
            continue;
        }
        while(r < queries[i].r) add(++r);
        while(l > queries[i].l) add(--l);
        while(r > queries[i].r) del(r--);
        while(l < queries[i].l) del(l++);
        ans[queries[i].idx] = get_ans(queries[i].v);
    }
}
 
 
int main(){
    io_boost;
    cin >> N;
    vector<int> roots;
    for(int v = 0, u; v < N; v++){
        cin >> u;
        if(u == 0) roots.push_back(v);
        else{
            u--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for(int root : roots)
        dfs(root, root, 0);
    cin >> M;
    for(int i = 0, u, p; i < M; i++){
        cin >> u >> p;
        u--;
        int LCA = lca(u, p);
        queries[i].v = u;
        queries[i].l = in[LCA];
        queries[i].r = out[LCA];
        queries[i].idx = i;
        queries[i].p = p > dist[u];
    }
    mos();
    for(int i = 0; i < M; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}