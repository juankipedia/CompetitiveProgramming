#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long int lli;
 
const int MAXN = 40004, MAXM = 100005, LOG2N = 16;
vector<int> g[MAXN];
int a[2 * MAXN], up[MAXN][LOG2N + 5], dist[MAXN], N, M, in[MAXN], out[MAXN], t = 0;
lli w[MAXN];
 
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
 
struct Query{
    int l, r, idx, lca;
};
Query queries[MAXM];
pair<lli, int> b[2 * MAXN];
int BLOCK_SIZE, l, r, freq[2 * MAXN], res, ans[MAXM], id[2 * MAXN], cnt[MAXN];
 
bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}
 
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
    if(cnt[a[i]] % 2) add(i);
    else del(i);
}
 
 
int get_ans(int LCA){
    if(LCA != -1){
        update(in[LCA]);
        int resi = res;
        update(in[LCA]);
        return resi;
    }
    else return res;
}
 
void mos(){
    BLOCK_SIZE = sqrt(t);
    for(int i = 0; i < t; i++)
        b[i] = {w[a[i]], i};
    sort(b, b + t);
    int cid = 0;
    for(int i = 0; i < t; i++){
        if(i != 0 && b[i - 1].first != b[i].first) cid++;
        id[b[i].second] = cid;
    }
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
    for(lli i = 0, u, v; i < M; i++){
        cin >> u >> v;
        u--; v--;
        lli LCA = lca(u, v);
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
  