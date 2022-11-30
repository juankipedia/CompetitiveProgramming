/**
 * Lowest common ancestor (LCA). binary lifting
 * 
 * O(nlgn) in dfs function and O(lg(n)) per query.
 * 
 * We will find the LCA by lifting up each vertex until they find each other.
 * 
 * Algorithm:
 * 1.- run dfs(root, root, 0)
 * 
 *     Binary lifting, we will jump in powers of 2.
 *     up[u][i] means we jump up from vertex u, 2^i positions.
 *     here we are calculating jumps for each power of 2.
 * 
 * 2.- call lca(u, v) for each query
 * 
 *     First both u, v should be at the same distance from the root (height).
 *     After that u is at the same hight of v, if u == v it means v was the LCA of u.
 *     Then, we want to lift up u and v to be childs of the lca, if jumping from 
 *     u and v a distance 2^i ends in the same vertex (up[u][i] == up[v][i]) it 
 *     means that it is the LCA or the vertex is above the LCA, then we do not jump that distance,
 *     we always want to be under the LCA in order to end at the childs of the LCA.
 * 
 **/

struct Lca{
    int N, LOG2N, root;
    vector<int> dist;
    vector<vector<int>> up;

    Lca(int n, int r, vector<int> g[]){
        N = n;
        root = r;
        LOG2N = log2(N);
        up.assign(N +  5, vector<int>(LOG2N + 1, 0));
        dist.assign(N + 5, 0);
        dfs(root, root, 0, g);
    }

    void dfs(int u, int p, int h, vector<int> g[]){
        dist[u] = h;
        up[u][0] = p;
        
        for(int i = 1; i <= LOG2N; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];
        
        for(int v: g[u])
            if(v != p) dfs(v, u, h + 1, g);
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

};


/**
 * Lowest common ancestor (LCA). euler tour + sparse table.
 * 
 * We will find the LCA of each query by building the euler tour and finding the vertex with the minimun height
 * in the segment [first[u], first[v]].  First[] stores for each vertex v its first occurrence in euler tour.
 * 
 **/

struct Lca{
    int N, LOG2N;
    vector<int> first, height, lg2, path;
    vector<vector<int>> st;

    Lca(int n, int root, vector<int> g[]){
        N = n;
        first.assign(N + 5, 0);
        height.assign(N + 5, 0);
        
        dfs(root, root, 0, g);
        LOG2N = log2(path.size() + 5);
        lg2.assign(path.size() + 5, 0);
        st.assign(path.size() + 5, vector<int>(LOG2N + 5, 0));
        build();
    }

    void dfs(int u, int p, int h, vector<int> g[]){
        height[u] = h;
        first[u] = path.size();
        path.push_back(u);

        for(int v: g[u])
            if(v != p)
                dfs(v, u, h + 1, g),
                path.push_back(u);
    }   

    void build(){
        
        lg2[1] = 0;

        for(int i = 2; i <= path.size(); i++) lg2[i] = lg2[i / 2] + 1;
        for(int i = 0; i < path.size(); i++) st[i][0] = path[i];
        for(int j = 1; j <= LOG2N; j++){
            for(int i = 0; i + (1 << j) <= path.size(); i++){
                int a = st[i][j - 1], b = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = height[a] < height[b] ? a : b;
            }
        }
    }

    int lca(int u, int v){
        int L = first[u], R = first[v];
        if(L > R) swap(L, R); 
        int lg = lg2[R - L + 1];
        int l = st[L][lg], r = st[R - (1 << lg) + 1][lg];
        if(height[l] < height[r]) return l;
        else return r;
    }

};