vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> &g){
    int size = 1, max_c_size = 0;
    for(int c : g[v])
        if(c != parent[v]){
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, g);
            size += c_size;
            if(c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    return size;
}

void decompose(int v, int h, vector<vector<int>> &g){
    head[v] = h, pos[v] = cur_pos++;
    if(heavy[v] != -1) decompose(heavy[v], h, g);
    for(int c : g[v])
        if(c != parent[v] && c != heavy[v])
            decompose(c, c, g);
}

void init(vector<vector<int>> &g){
    int n = g.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, g);
    decompose(0, 0, g);
}
