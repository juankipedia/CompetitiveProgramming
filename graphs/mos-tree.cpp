# include <bits/stdc++.h>
using namespace std;
# define endl "\n"
# define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ull = unsigned long long;
using ll = long long;
/*
    Que mira bobo ? 
    JUANKI
*/

/**
 *  STATEMENT: You are given a tree with N nodes. The tree nodes are numbered from 1 to N. Each node has an integer weight.
 *  We will ask you to perform the following operation:
 *      u - v : ask for how many different weights of nodes are on the path from u to v.
 * 
 *  SOLUTION: Transform the tree in to an array using MODIFIED version of euler tour path, apply mo's algorithm over the resulting array.
 *  We have 2 cases, for a path u - v:
 *      1- if lca(u, v) != u && lca(u, v) != v, then the answer for the query is mos([out[u], in[v]] U {LCA(u, v)}).
 *      2- if lca(u, v) == u || lca(u, v) == v, then the answer for the query is mos([in[u], in[v]])
 * 
 *  NOTE: if some vertex appears in a segment of the euler tour an odd number of times then its value is included in the segment, 
 *  it is not included otherwise.
 **/

 
const int MAXN = 40004, MAXM = 100005, LOG2N = 16;
vector<int> g[MAXN];

// EULER TOUR and LCA.

int a[2 * MAXN], up[MAXN][LOG2N + 5], dist[MAXN], N, M, in[MAXN], out[MAXN], t = 0;
ll w[MAXN];

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
 
int lca(int u, int v){
    if(dist[u] < dist[v]) swap(u, v);
    int offset = dist[u] - dist[v];
    for(int i = 0; i <= LOG2N; i++)
        if(offset & (1 << i)) u = up[u][i];
    if(u == v) return u;
    for(int i = LOG2N - 1; i >= 0; i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

// MO's ALGORITHM

struct Query{
    int l, r, idx, lca;
};
Query queries[MAXM];
pair<ll, int> b[2 * MAXN];

// id[] stores ids coordinates compression for weights of the vertices.
int BLOCK_SIZE, l, r, freq[2 * MAXN], res, ans[MAXM], id[2 * MAXN], cnt[MAXN];
 
bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}

// freq[id[i]] frequency of the weight of the a[i] vertex. 

void add(int i){
    if(!freq[id[i]]) res++;
    freq[id[i]]++;
}
 
void del(int i){
    freq[id[i]]--;
    if(!freq[id[i]]) res--; 
}
 
void update(int i){
    cnt[a[i]]++;
    if(cnt[a[i]] % 2) add(i); // if we get an odd frequency then add the element.
    else del(i); // if we get an even frequency then delete the element.
}
 
 
int get_ans(int LCA){
    if(LCA != -1){ // if we are in the first case then the answer is mos([out[u], in[v]] U {LCA(u, v)}).
        update(in[LCA]);
        int resi = res;
        update(in[LCA]);
        return resi;
    }
    else return res;
}
 
void mos(){
    BLOCK_SIZE = sqrt(t);
    // Coordinates compression for weights
    for(int i = 0; i < t; i++)
        b[i] = {w[a[i]], i};
    sort(b, b + t);
    int cid = 0;
    for(int i = 0; i < t; i++){
        if(i != 0 && b[i - 1].first != b[i].first) cid++;
        id[b[i].second] = cid;
    }
    // Answering queries.
    sort(queries, queries + M, cmp);
    l = 1;
    r = 0;
    for(int i = 0; i < M; i++){
        while(r < queries[i].r) update(++r);
        while(l > queries[i].l) update(--l);
        while(r > queries[i].r) update(r--);
        while(l < queries[i].l) update(l++);
        ans[queries[i].idx] = get_ans(queries[i].lca);
    }
}
 
 
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> w[i];
    for(int i = 0, u, v; i < N - 1; i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0, 0);
    for(ll i = 0, u, v; i < M; i++){
        cin >> u >> v;
        u--; v--;
        ll LCA = lca(u, v);
        if(in[u] > in[v]) swap(u, v);
        if(LCA == u){
            queries[i].l = in[u];
            queries[i].r = in[v];
            queries[i].lca = -1;
        }
        else{
            queries[i].l = out[u];
            queries[i].r = in[v];
            queries[i].lca = LCA;
        }
        queries[i].idx = i;
    }
    mos();
    for(int i = 0; i < M; i++) cout << ans[i] << endl;
    return 0;
}
