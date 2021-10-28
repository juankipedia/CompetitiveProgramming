/**
 *
 * KRUSKAL
 * find minimum spanning tree.
 * time complexity: O(E log(V)).
 * 
 * */

# define U(t) t.second.first
# define V(t) t.second.second
# define W(t) t.first
typedef pair<lli, pair<int, int>> edge; 

const int MAXM = 100000, MAXN = 100000;
edge edges[MAXM], mst[MAXN];
int N, M;

struct DSU {
    int n, comp = n;
    vector<int> p, len;
    DSU(int n) : n(n){
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

lli kruskal(){
    DSU dsu(N);
    sort(edges, edges + M);
    lli sum = 0;
    for(int i = 0, e = 0; i < N - 1;){
        int u = dsu.find(U(edges[e])), v = dsu.find(V(edges[e]));
        if(u != v){
            dsu.join(u, v);
            mst[i++] = edges[e];
            sum += W(edges[e]);
        }
        e++;
    }
    return sum;
}