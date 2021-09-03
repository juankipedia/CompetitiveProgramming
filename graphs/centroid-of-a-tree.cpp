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