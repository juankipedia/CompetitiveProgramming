/**
 *
 * KRUSKAL
 * find minimum spanning tree.
 * time complexity: O(E log(V)).
 * 
 * */

struct edge{
    ll w;
    int u, v;
    bool operator < (const edge &e){
        return w < e.w;
    }
};

const int MAXM = 100000, MAXN = 100000;
edge edges[MAXM], mst[MAXN];
int N, M;

struct Dsu{
    int n, comp = n;
    vector<int> p, len;
    Dsu(int n) : n(n){
        p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
        len.assign(n + 10, 1);
    }
    int find(int n){ return p[n] = p[n] == n ? n : find(p[n]); }
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(len[a] < len[b]) swap(a, b);
        len[a] += len[b];
        p[b] = a;
        comp--;
    }
};

ll kruskal(){
    Dsu dsu(N);
    sort(edges, edges + M);
    ll sum = 0;
    for(int i = 0, e = 0; i < N - 1;){
        int u = dsu.find(edges[e].u), v = dsu.find(edges[e].v);
        if(u != v){
            dsu.join(u, v);
            mst[i++] = edges[e];
            sum += edges[e].w;
        }
        e++;
    }
    return sum;
}
