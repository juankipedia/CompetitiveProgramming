#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<lli>::max();
typedef pair<lli, int> pli;
 
int n, m, k, u, v, ku[1000], kv[1000];
lli w;
vector<pli> g[1000];
lli d[1000][1000];


void sp(int s){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    d[s][s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        lli pd = pq.top().first;
        pq.pop();
        if(pd > d[s][u]) continue;
        for(pli &p : g[u]){
            int v = p.second;
            lli w = p.first;
            if(d[s][v] > d[s][u] + w){
                d[s][v] = d[s][u] + w;
                pq.push({d[s][v], v});
            }
        }
    }
}
 
int main(){
    io_boost;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = oo;

    bool v[n] = {false};
    
    for(int i = 0; i < k; i++){
        cin >> ku[i] >> kv[i];
        ku[i]--; kv[i]--;
        if(!v[ku[i]]){ sp(ku[i]); v[ku[i]] = true;}
        if(!v[kv[i]]){ sp(kv[i]); v[kv[i]] = true;}
    }
    lli ans = oo;
    for(int j = 0; j < n; j++){
        for(pli &p : g[j]){
            lli ds = 0;
            for(int i = 0; i < k; i++){
                lli nd = min({d[ku[i]][j] + d[kv[i]][p.second], d[ku[i]][p.second] + d[kv[i]][j], d[ku[i]][kv[i]]});
                if(ku[i] == kv[i]) nd = 0;          
                ds += nd;
            }
            ans = min(ans, ds);
        }
    }
    cout << ans << endl;
    return 0;
}