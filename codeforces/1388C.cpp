#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli INF = numeric_limits<lli>::max();
int t, n, U, V;
lli m, p[100000], h[100000];
 
pair<lli, lli> count(vector<int> T[], int u, int parent){
    lli au = p[u], gv = 0;
    for(const int v: T[u]){
        if(v == parent) continue;
        auto ci = count(T, v, u);
        if(ci.first == INF){
            au = INF;
            break;
        }
        au += ci.first; gv += ci.second;
    }
    if(au == INF) return {INF, INF};    
    lli gu = (au + h[u]) / 2;
    if((au + h[u]) % 2) return {INF, INF};
    if(gu  < 0 || gu > au) return {INF, INF};
    if(gv > gu) return {INF, INF};
    return{au, gu};
}
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> h[i];
        vector<int> T[n];
        for(int i = 0; i < n - 1; i++){
            cin >> U >> V;
            U--; V--;
            T[U].push_back(V);
            T[V].push_back(U);
        }
 
        if(count(T, 0, -1).first != INF) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}