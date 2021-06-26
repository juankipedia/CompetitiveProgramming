# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli MAXN = 2e5 + 5;
lli t, n, m, V[MAXN], T[MAXN], cs[2];
vector<lli> g[MAXN];
 
bool bipartite(){
    lli color[MAXN];
    memset(color, -1, sizeof(color));
    queue<lli> q;
    color[0] = 1;
    q.push(0);
    while(!q.empty()){
        lli u = q.front();
        q.pop();
        cs[color[u]] += T[u] - V[u]; 
        for(lli v: g[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}
 
 
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        lli vs = 0, ts = 0;
        for(int i = 0; i < n; i++) g[i].clear();
        for(lli i = 0; i < n; i++) cin >> V[i], vs += V[i];
        for(lli i = 0; i < n; i++) cin >> T[i], ts += T[i];
        for(lli i = 0, u, v; i < m; i++){
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cs[0] = cs[1] = 0;
        if(bool(vs % 2) != bool(ts % 2)) cout << "NO" << endl;
        else{
            if(bipartite()){
                if(cs[0] == cs[1]) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else cout << "YES" << endl;
        }
    }
    return 0;
}