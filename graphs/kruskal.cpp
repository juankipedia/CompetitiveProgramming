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
int N, M, p_set[MAXN];

void build(){
    for(int i = 0; i < N; i++) p_set[i] = i;
}

int find(int a){
    if(p_set[a] != a) p_set[a] = find(p_set[a]);
    return p_set[a];
}

void join(int a, int b){
    p_set[find(a)] = find(b);
}

void kruskal(){
    sort(edges, edges + M);
    build();
    for(int i = 0, e = 0; i < N - 1;){
        int u = find(U(edges[e])), v = find(V(edges[e]));
        if(u != v){
            join(u, v);
            mst[i++] = edges[e];
        }
        e++;
    }
}