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
const int MAXV = 100001, MAXE = 10001;
int V, E;
tuple<int, int, lli> edges[MAXE];
# define U(t) get<0>(t)
# define V(t) get<1>(t)
# define W(t) get<2>(t)

bool bellman_ford(int src, vector<lli> &dist){
    dist.resize(MAXV, oo);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i++){
        for(int j = 0; j < E; j++){
            int u = U(edges[j]), v = V(edges[j]);
            lli w = W(edges[j]); 
            if(dist[u] != oo && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    //check for negative cycle
    for(int j = 0; j < E; j++){
        int u = U(edges[j]), v = V(edges[j]);
        lli w = W(edges[j]); 
        if(dist[u] != oo && dist[v] > dist[u] + w)
            return true; // negative cycle
    }
    return false;
}