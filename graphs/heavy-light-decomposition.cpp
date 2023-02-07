
struct Hld{
    vector<int> parent, depth, heavy, head, pos, len;
    int cur_pos, n;

    int dfs(int u, vector<int> g[]){
        int size = 1, mx = 0;
        for(int v : g[u])
            if(v != parent[u]){
                parent[v] = u, depth[v] = depth[u] + 1;
                int v_size = dfs(v, g);
                size += v_size;
                if(v_size > mx)
                    mx = v_size, heavy[u] = v;
            }
        return size;
    }

    void decompose(int u, int h, vector<int> g[]){
        head[u] = h, pos[u] = cur_pos++;
        if(heavy[u] != -1) decompose(heavy[u], h, g);
        for(int v : g[u])
            if(v != parent[u] && v != heavy[u])
                decompose(v, v, g);
    }

    Hld(int N, vector<int> g[]){
        n = N;
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        cur_pos = 0;

        dfs(0, g);
        decompose(0, 0, g);
    }

};


