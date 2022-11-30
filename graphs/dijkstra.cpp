/**
 * DIJKSTRA.
 * 
 * Find shortest path from source to all other vertices.
 * 
 * E: number of edges.
 * V: number of vertices.
 * time complexity: O(E log(V))
 * 
 * */

const lli oo = numeric_limits<lli>::max(), MAXN = 100000;
vector<pair<lli, int>> g[MAXN];
int N;

void dijkstra(int src, vector<lli> &dist){
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq; 
    dist.assign(N, oo); 
    pq.push({0, src}); 
    dist[src] = 0; 
    while(!pq.empty()){
        auto [pd, u] = pq.top();
        pq.pop();
        if(pd > dist[u]) continue;
        for(auto [w, v] : g[u])
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});    
            }
    }
} 

