#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
const lli oo = numeric_limits<lli>::max();

int n, m, k, U, V;
lli W;
vector<pair_l> g[100000];
map<int, int> mini[100000];
map<pair_l, int> t;

int main(){
    io_boost
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> U >> V;
        U--; V--;
        cin >> W;
        g[U].push_back({W, V});
        g[V].push_back({W, U});
    }
    for(int i = 0; i < k; i++){
        cin >> U >> W;
        U--;
        g[0].push_back({W, U});
        g[U].push_back({W, 0});
        ++t[{W, U}];
    }
    
    vector<lli> d(n, oo);

    priority_queue<pair_l, vector<pair_l>, greater<pair_l>> pq;
    d[0] = 0;

    pq.push({0, 0});
    while (!pq.empty()){
        U = pq.top().second;
        pq.pop();
        for(pair_l &p: g[U]){
            W = p.first;
            V = p.second;
            if(d[V] > d[U] + W){
                d[V] = d[U] + W;
                pq.push({d[U] + W, V});
                mini[V].clear();
                ++mini[V][U]; 
            }
            else if(d[V] == d[U] + W) ++mini[V][U];
        }
    }



    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mini[i].size() == 1 && mini[i].begin()->first == 0 && (t.find({d[i], i}) != t.end())) 
            if(mini[i][0] == t[{d[i], i}]) cnt++;
    }
    cout << k - cnt << endl;
    return 0;
}