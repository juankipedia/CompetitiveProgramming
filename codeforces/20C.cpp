#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
const lli oo = numeric_limits<lli>::max();

int n, m, U, V;
lli W;
vector<pair_l> g[100000];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> U >> V;
        U--; V--;
        cin >> W;
        g[U].push_back({W, V});
        g[V].push_back({W, U});
    }
    vector<lli> d(n, oo);
    vector<int> parent(n, -1);

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
                parent[V] = U;
            }
        }
    }
    if(d[n - 1] == oo){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    V = parent[n - 1];
    while(V != 0){
        ans.push_back(V);
        V = parent[V];
    }
    cout << 1 << " ";
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
    cout << n << endl;
    return 0;
}