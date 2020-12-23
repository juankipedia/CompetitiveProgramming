#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * PRIM'S ALGORITHM
 * find Minimum Spanning Tree (MST).
 * Time complexity O(E log(V))
 * 
 * */

typedef pair<lli, int> p_lli_i;

const lli oo = numeric_limits<lli>::max();

const int MAXN = 100000;
int N, M, parent[MAXN];
vector<p_lli_i> g[MAXN];

void prim(){
    bool in_mst[N] = {false};
    vector<lli> key(N, oo);
    priority_queue<p_lli_i, vector<p_lli_i>, greater<p_lli_i>> pq;
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        in_mst[u] = true;
        for(p_lli_i &p: g[u]){
            int v = p.second;
            lli w = p.first;
            if(!in_mst[v] && key[v] > w){
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }   
}