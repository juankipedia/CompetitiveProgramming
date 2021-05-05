# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 300005, MOD = 998244353;
int N, M;
vector<int> g[MAXN];
vector<lli> ans;

bool bipartite(int color[], int src){
    queue<int> q;
    color[src] = 1;
    q.push(src);
    bool single = true;
    vector<int> components;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u != src) single = false;
        components.push_back(u);
        for(int v: g[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]) return false;
        }
    }
    lli ans1 = 1, ans2 = 1;
    for(auto component : components)
        if(color[component] == 1) ans1 = (ans1 * 2) % MOD;
        else ans2 = (ans2 * 2) % MOD;
        
    if(single) ans.push_back(3);
    else ans.push_back(ans1 + ans2);
    return true;
}


int main(){
    io_boost;
    int t;
    cin >> t;
    while(t--){
        cin >> N >> M;
        int color[N];
        bool lvl[N];
        ans.clear();
        for(int i = 0; i < N; i++) g[i].clear(), color[i] = -1, lvl[i] = false;;
        for(int i = 0, u, v; i < M; i++){
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool b = true;
        for(int i = 0; i < N; i++)
            if(color[i] == -1)
                b = b && bipartite(color, i);

        if(!b) cout << 0 << endl;
        else{
            lli ans1 = 1;
            for(auto e: ans) ans1 = (ans1 * e) % MOD;
            cout << ans1 << endl;
        }

    }
    return 0;
}