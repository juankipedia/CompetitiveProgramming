#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<ulli, int> pair_l;
const ulli oo = numeric_limits<ulli>::max();

int n, m, k, U, V;
vector<pair_l> g[100000];
ulli W, T1, T2;
vector<ulli> t[100000];

ulli get_time(int i, ulli ti){
    if(t[i].size() == 0) return ti;
    int pos = lower_bound(t[i].begin(), t[i].end(), ti) - t[i].begin();
    if(pos == t[i].size() - 1) return ti;
    else if(pos % 2 && t[i][pos] > ti) return ti;
    else if(pos % 2 && t[i][pos] == ti) return t[i][pos + 1];
    else return t[i][pos];
}

int main(){
    cin >> n >> m;
    while(m--){
        cin >> U >> V >> W;
        U--; V--;
        g[U].push_back({W, V});
        g[V].push_back({W, U});       
    }
    
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k == 0) continue;
        cin >> T1;
        if(T1 != 0){ t[i].push_back(0); t[i].push_back(T1);}
        for(int j = 1; j < k; j++){
            cin >> T2;
            if(T2 != (T1 + 1)){
                t[i].push_back(T1 + 1);
                t[i].push_back(T2);
            }
            T1 = T2;
        }
        t[i].push_back(T1 + 1);
        t[i].push_back(oo);
    }

    vector<ulli> d(n, oo);
    priority_queue<pair_l, vector<pair_l>, greater<pair_l>> pq;
    d[0] = 0;

    pq.push({0, 0});
    while (!pq.empty()){
        U = pq.top().second;
        ulli pd = pq.top().first;
        ulli wt = get_time(U, pd) - pd;
        pq.pop();
        if(pd > d[U]) continue;
        for(pair_l &p: g[U]){
            W = p.first;
            V = p.second;
            if(d[V] > (d[U] + wt + W)){
                d[V] = d[U] + W + wt;
                pq.push({d[U] + W + wt, V});
            }
        }
    }
    if(d[n - 1] == oo) cout << -1 << endl;
    else cout << d[n - 1] << endl;

    return 0;
}