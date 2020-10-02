#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pli;

const lli oo = numeric_limits<lli>::max();
const long double ood = numeric_limits<long double>::max();
int n, m, u, v, S, D, K, Q, A[100000], B[100000];
lli w;
long double t_d;
vector<pli> g[100001];

void sp(vector<lli> &d, int s){
    d[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    while (!pq.empty()){
        u = pq.top().second;
        lli pd = pq.top().first;
        pq.pop();
        if(pd > d[u]) continue;
        for(pli &p: g[u]){
            v = p.second;
            w = p.first;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});    
            }
        }
    }
    
}

int main(){
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    cin >> K;
    for(int i = 0; i < K; i++) cin >> A[i];
    cin >> Q;
    for(int i = 0; i < Q; i++) cin >> B[i];
    cin >> S >> D;

    vector<lli> dt(n, oo), dbd(n, oo), db(n + 1, oo);
    sp(dt, S);
    sp(dbd, D);
    t_d = dt[D];
    for(int i = 0; i < K; i++){
        g[n].push_back({0, A[i]});
        g[A[i]].push_back({0, n});
    }
    sp(db, n);
    long double minpd = ood;
    for(int i = 0; i < Q; i++){
        minpd = min((long double)db[B[i]] + (long double)dbd[B[i]] / 2, minpd);
    }
    minpd = min(minpd, (long double)db[D]);
    
    if(minpd <= t_d) cout << -1 << endl;
    else cout << (lli)t_d << endl;
    return 0;
}