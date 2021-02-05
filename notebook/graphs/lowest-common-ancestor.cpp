#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

/**
 * Lowest common ancestor (LCA). binary lifting
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
    // First both u, v should be at the same distance from the root (height).
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
 * Lowest common ancestor (LCA). euler tour + sparse table.
 * 
 * We will find the LCA of each query by building the euler tour and finding the vertex with the minimun height
 * in the segment [first[u], first[v]].  Which stores for each vertex v its first occurrence in euler tour.
 * 
 **/

const int MAXN = 1000;

int t, N, M, q, first[MAXN], height[MAXN];
vector<int> g[MAXN], a;

void dfs(int u, int p, int h){
    height[u] = h;
    first[u] = a.size();
    a.push_back(u);
    for(int v: g[u]){
        if(v != p){
            dfs(v, u, h + 1);
            a.push_back(u);
        }
    }
}   

const int LOG2N = 11;
int lg2[2 * MAXN + 1], st[2 * MAXN][LOG2N + 5];

// CALL BUILD before asking for LCA.
void build(){
    dfs(0, 0, 0);
    // Builds sparse table.
    lg2[1] = 0;
    for(int i = 2; i <= a.size(); i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < a.size(); i++) st[i][0] = a[i];
    for(int j = 1; j <= LOG2N; j++){
        for(int i = 0; i + (1 << j) <= a.size(); i++){
            int a = st[i][j - 1], b = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = height[a] < height[b] ? a : b;
        }
    }
}

int LCA(int u, int v){
    int L = first[u], R = first[v];
    if(L > R) swap(L, R); 
    int lg = lg2[R - L + 1];
    int l = st[L][lg], r = st[R - (1 << lg) + 1][lg];
    if(height[l] < height[r]) return l;
    else return r;
}