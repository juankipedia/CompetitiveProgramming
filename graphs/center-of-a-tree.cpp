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