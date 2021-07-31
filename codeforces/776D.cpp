# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 100005;
int n, m, val[MAXN], color[MAXN];;
vector<pair<int, int>> g[MAXN];
bool ans = true;

void dfs(int u){
    for(auto &[v, val]: g[u]){
        if(color[v] != -1){
            if(val == 1) ans = ans & (color[v] == color[u]);
            else ans = ans & (color[v] != color[u]);
            continue;
        }
        if(val == 1) color[v] = color[u], dfs(v);
        else color[v] = color[u] == 1 ? 0 : 1, dfs(v);
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> val[i];
    vector<int> edges[m + 5];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0, r; j < x; j++){
            cin >> r;
            r--;
            assert(r < m);
            edges[r].push_back(i);
        }
    } 
    for(int i = 0; i < m; i++){
        g[edges[i][0]].push_back({edges[i][1], val[i]});
        g[edges[i][1]].push_back({edges[i][0], val[i]});
    }
    memset(color, -1, sizeof(color));
    for(int i = 0; i < n; i++){
        if(color[i] == -1) color[i] = 1, dfs(i);
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}