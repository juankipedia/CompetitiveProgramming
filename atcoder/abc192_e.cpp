#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100000;
const lli oo = numeric_limits<lli>::max();
typedef pair<lli, int> p_lli_i;
typedef pair<pair<lli, lli>, int> pp;
vector<pp> g[MAXN];

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
        for(pp &p: g[u]){
            int v = p.second;
            lli t = p.first.first;
            lli k = p.first.second;
            if(dist[u] != 0){
                lli ki = ((dist[u] + k - 1) / k) * k;
                t += ki - dist[u];
                //cout << (dist[u] + k - 1 / k) << " " << dist[u] << endl;
            }
            //cout << u << " - " << v << " " << t << endl;
            if(dist[v] > dist[u] + t){
                dist[v] = dist[u] + t;
                pq.push({dist[v], v});    
            }
        } 
    }
}
int N, M, X, Y;
int main(){
    cin >> N >> M >> X >> Y;
    X--; Y--;
    for(int i = 0, A, B, T, K; i < M; i++){
        cin >> A >> B >> T >> K;
        A--; B--;
        g[A].push_back({{T, K}, B});
        g[B].push_back({{T, K}, A});
    }
    vector<lli> dist;
    dijkstra(X, dist);
    if(dist[Y] == oo) cout << -1 << endl;
    else cout << dist[Y] << endl;
    return 0;
}