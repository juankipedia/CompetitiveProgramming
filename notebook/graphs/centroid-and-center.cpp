#include <bits/stdc++.h>
using namespace std;

/**
 * CENTROID:
 * let S(v) be the size of the subtree rooted on v.
 * 
 * A centroid is a node v such that.
 *      maxi(n - S(v), S(u1), S(u2), .. S(um)) <= n/2
 * where ui is the i'th child of v.
 * 
 * Every tree only have one or two centroids.
 * 
 * **/
vector<int> centroids(vector<int> g[], int n){
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

/**
 * CENTER:
 * Every tree has a center consisting of one vertex or two adjacent vertices. 
 * The center is the middle vertex or middle two vertices in every longest path.
 * **/
vector<int> centers(vector<int> t[], int n){
    int root, maxdist = 0, parent[n];
    function<void (int, int, vector<int>[], int)> dfs = [&](int u, int p, vector<int> t[], int d){
        if(maxdist < d){
            maxdist = d;
            root = u;
        }
        parent[u] = p;
        for(int v: t[u])
            if(v != p)
                dfs(v, u, t, d + 1);
    };
    dfs(0, -1, t, 0);
    maxdist = 0;
    dfs(root, -1, t, 0);
    int cur = root;
    vector<int> path;
    while (cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    if(path.size() % 2) return {path[path.size() / 2]};
    else  return{path[path.size() / 2], path[(path.size() / 2) - 1]};
}





