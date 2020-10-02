#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pll;
const lli oo = numeric_limits<lli>::max();

int n, U, V;
string Aij;
vector<pll> g[100];
lli W, BW;

int main(){
    io_boost;
    cin >> n;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            cin >> Aij;
            if(Aij != "x"){
                g[i].push_back({stoll(Aij), j});
                g[j].push_back({stoll(Aij), i});
            }
        }
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<lli> d(n, oo);
    d[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        BW = pq.top().first; U = pq.top().second;
        pq.pop();
        if(BW > d[U]) continue;
        for(pll &p: g[U]){
            V = p.second;
            W = p.first;
            if(d[V] > d[U] + W){
                d[V] = d[U] + W;
                pq.push({d[V], V});
            }
        }
    }
    lli ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}