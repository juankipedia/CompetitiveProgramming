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

const ll oo = numeric_limits<ll>::max(), MAXN = 100000;
vector<pair<ll, int>> g[MAXN];
int N;

void dijkstra(int src, vector<ll> &dist){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; 
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
