/**
 *
 * BELLMAN FORD
 * 
 * Find shortest distance from source (src) to all other vertices, graph could contain
 * negative weight edges.
 * Time complexity O(VE);
 * 
 * */

const lli oo = numeric_limits<lli>::max();
int N, M;

vector<tuple<int, int, lli>> edges;

bool bellman_ford(int src, vector<lli> &dist){
    dist.assign(N, oo);
    dist[src] = 0;
    bool x;
    for(int i = 0; i < N; i++){
        x = 0;
        for(int j = 0; j < M; j++){
            auto [u, v, w] = edges[j]; 
            if(dist[u] != oo && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w,
                x = 1;
        }
    }
    // return 1 if there is a negative weith cycle
    return x;
}