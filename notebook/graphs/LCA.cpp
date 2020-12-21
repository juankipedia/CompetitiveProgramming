#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

/**
 * Lowest common ancestor (LCA). Answring queries online
 * 
 * O(nlgn) in dfs function and O(lg(n)) per query.
 * 
 * We will find the LCA by lifting up each vertex until they find each other.
 * 
 **/

const int MAXN = 1000000;
const int LOG2N = 20; // log2(MAXN)
vector<int> g[MAXN];
int up[MAXN][LOG2N + 1]; //sparse table.
int dist[MAXN];

void dfs(int u, int p, int h){
    dist[u] = h;
    /*
    * Binary lifting, we will jump in powers of 2.
    * up[u][i] means we jump up from vertex u, 2^i positions.
    * here we are calculating jumps for each power of 2.
    */
    up[u][0] = p;
    for(int i = 1; i <= LOG2N; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for(int v: g[u])
        if(v != p) dfs(v, u, h + 1);
}

int lca(int u, int v){
    // First both u, v should be at the same distance from the root (hight).
    if(dist[u] < dist[v]) swap(u, v);
    int offset = dist[u] - dist[v];
    for(int i = 0; i <= LOG2N; i++)
        if(offset & (1 << i)) u = up[u][i];
    // At this point u is at the same hight of v, if u == v it means v was the LCA of u. 
    if(u == v) return u;
    // We want to lift up u and v to be childs of the lca, if jumping from 
    // u and v a distance 2^i ends in the same vertex (up[u][i] == up[v][i]) it 
    // means that it is the LCA or the vertex is above the LCA, then we do not jump that distance,
    // we always want to be under the LCA in order to end at the childs of the LCA.
    for(int i = LOG2N - 1; i >= 0; i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}



/**
 * Lowest common ancestor (LCA). Answering queries offline.
 * 
 * We will find the LCA of each query using small to large strategy.
 * 
 **/

const int MAXQ = 1000; // maximun number of queries.
set<int> s[MAXN]; // For each node we stores queries related to it.
int ans[MAXQ]; // ans[i] is the answer of query number i.

void dfs(int u, int p){
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, u);
        if(s[v].size() > s[u].size()) swap(s[v], s[u]);
        for(int q: s[v]){
            if(s[u].count(q)){ // if set u has query q then lca for query q is u.
                ans[q] = u;
                s[u].erase(q);
            }
            else s[u].insert(q);
        }
    }
}

// function to store queries.
void input_queries(){
    int q;
    cin >> q;
    for(int i = 0, u, v; i < q; i++){
        cin >> u >> v;
        u--; v--;
        if(u == v){
            ans[i] = u;
            continue;
        }
        s[u].insert(i);
        s[v].insert(i);
    }
}

