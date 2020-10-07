#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pli;

const lli oo = numeric_limits<lli>::max();
lli W;
int n, m, U, V;
lli w[1000], d[1000];

void sp(vector<pli> g[]){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});
    d[1] = 0;
    lli di;
    while(!pq.empty()){
        U = pq.top().second;
        di = pq.top().first;
        pq.pop();
        if(di > d[U]) continue;
        for(auto &p: g[U]){
            V = p.second;
            W = p.first;
            if(d[V] > d[U] + W){
                d[V] = d[U] + W;
                pq.push({d[V], V});
            }
        }
    }
    return;
}

lli ways(vector<pli> g[], int tgt){
    if(tgt == 0) return 1; 
    if(w[tgt] != -1) return w[tgt];
    lli ww = 0;
    for(auto &p: g[tgt])
        if(d[p.second] > d[tgt]) ww += ways(g, p.second);
    return w[tgt] = ww;
}

int main(){
    io_boost;
    while(cin >> n && n != 0){
        cin >> m;
        vector<pli> g[n];
        for(int i = 0; i < m; i++){
            cin >> U >> V >> W;
            U--; V--;
            g[U].push_back({W, V});
            g[V].push_back({W, U});
        }
        for(int i = 0; i < n; i++) d[i] = oo;
        sp(g);
        memset(w, -1, sizeof(w));
        cout << ways(g, 1) << endl;
    }
    return 0;
}