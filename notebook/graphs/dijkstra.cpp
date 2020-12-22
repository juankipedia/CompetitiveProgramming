#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100000;
const lli oo = numeric_limits<lli>::max(); 
typedef pair<lli, int> p_lli_i;
vector<p_lli_i> g[MAXN];

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

