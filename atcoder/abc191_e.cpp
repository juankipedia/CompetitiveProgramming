#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, M;
const int MAXN = 2000;
const lli oo = numeric_limits<lli>::max();
typedef pair<lli, int> p_lli_i;
vector<p_lli_i> g[MAXN];
vector<lli> distances[MAXN];

void dijkstra(int src, vector<lli> &dist){
    priority_queue<p_lli_i, vector<p_lli_i>, greater<p_lli_i>> pq; 
    dist.resize(MAXN, oo); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
    while(!pq.empty()){
        int u = pq.top().second; 
        lli pd = pq.top().first;
        pq.pop();
        if(pd > dist[u]) continue;
        for(p_lli_i &p: g[u]){
            int v = p.second;
            lli w = p.first;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});    
            }
        } 
    }
} 

int main(){
    cin >> N >> M;
    lli self[N];
        lli ans[N];
    for(int i = 0; i < N; i++) ans[i]= self[i] = oo;
    for(int i = 0, u, v; i < M; i++){
        lli w;
        cin >> u >> v >> w;
        u--; v--;
        if(u == v) self[u] = min(self[u], w);
        else g[u].emplace_back(w, v);
    }
    for(int i = 0; i < N; i++){
        distances[i].assign(N, oo);
        dijkstra(i, distances[i]);
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(distances[i][j] == oo || distances[j][i] == oo) continue;
            if(i != j) ans[i] = min(distances[i][j] + distances[j][i], ans[i]);
        }
        ans[i] = min(ans[i], self[i]);
    }
    for(int i = 0; i < N; i++)
        if(ans[i] == oo) cout << -1 << endl;
        else cout << ans[i] << endl;
    return 0;
}