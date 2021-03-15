# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAXN = 200000;
 
int N, M;
const lli oo = numeric_limits<lli>::max();
typedef pair<lli, pair<int, pair<int, int>>> p_lli_i;
vector<pair<lli, int>> g[MAXN];
 
lli dist[MAXN][2][2];
 
void dijkstra(int src){
    priority_queue<p_lli_i, vector<p_lli_i>, greater<p_lli_i>> pq; 
 
    for(int i = 0; i < N; i++)
        dist[i][0][0] = dist[i][1][0] = dist[i][0][1] = dist[i][1][1] = oo;
 
    pq.push({0, {src, {0, 0}}}); 
    dist[src][0][0] = 0; 
    while(!pq.empty()){
        auto [pd, p] = pq.top();
        auto [u, pp] = p;
        auto [mx, mn] = pp;
        pq.pop();
        if(pd > dist[u][mx][mn]) continue;
        for(auto [w, v]: g[u]){
            if(mx == 1 && mn == 0){
                if(dist[v][1][0] > dist[u][1][0] + w){
                    dist[v][1][0] = dist[u][1][0] + w;
                    pq.push({dist[v][1][0], {v, {1, 0}}});
                }
                if(dist[v][1][1] > dist[u][1][0] + 2 * w){
                    dist[v][1][1] = dist[u][1][0] + 2 * w;
                    pq.push({dist[v][1][1], {v, {1, 1}}});
                }
            }
            else if(mx == 0 && mn == 1){
                if(dist[v][0][1] > dist[u][0][1] + w){
                    dist[v][0][1] = dist[u][0][1] + w;
                    pq.push({dist[v][0][1], {v, {0, 1}}});
                }
                if(dist[v][1][1] > dist[u][0][1]){
                    dist[v][1][1] = dist[u][0][1];
                    pq.push({dist[v][1][1], {v, {1, 1}}});
                }
            }
            else if(mx == 0 && mn == 0){
                if(dist[v][1][0] > dist[u][0][0]){
                    dist[v][1][0] = dist[u][0][0];
                    pq.push({dist[v][1][0], {v, {1, 0}}});
                }
                if(dist[v][0][1] > dist[u][0][0] + 2 * w){
                    dist[v][0][1] = dist[u][0][0] + 2 * w;
                    pq.push({dist[v][0][1], {v, {0, 1}}});
                }
                if(dist[v][1][1] > dist[u][0][0] + w){
                    dist[v][1][1] = dist[u][0][0] + w;
                    pq.push({dist[v][1][1], {v, {1, 1}}});
                }
                if(dist[v][0][0] > dist[u][0][0] + w){
                    dist[v][0][0] = dist[u][0][0] + w;
                    pq.push({dist[v][0][0], {v, {0, 0}}});
                }
            }
            else{
                if(dist[v][1][1] > dist[u][1][1] + w){
                    dist[v][1][1] = dist[u][1][1] + w;
                    pq.push({dist[v][1][1], {v, {1, 1}}});
                }
            }
        } 
    }
} 
 
int main(){
    cin >> N >> M;
    for(lli i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
 
    dijkstra(0);
    for(int i = 1; i < N; i++) cout << dist[i][1][1] << " ";
    cout << endl;
    return 0;
}