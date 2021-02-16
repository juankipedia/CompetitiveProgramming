#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int t, p[100], n;
pair<int, int> g[105];

int build(int l, int r){
    if(l > r) return -1;
    int root = 0, pos;
    for(int i = l; i <= r; i++){
        if(p[i] > root){
            root = p[i];
            pos = i;
        }
    }
    g[root].first = build(l, pos - 1);
    g[root].second = build(pos + 1, r);
    return root;
}

int d[105];

void dfs(int u, int di){
    d[u] = di;
    if(g[u].first != -1) dfs(g[u].first, di + 1);
    if(g[u].second != -1) dfs(g[u].second, di + 1);
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        build(0, n - 1);
        dfs(n, 0);
        for(int i = 0; i < n; i++) cout << d[p[i]] << " ";
        cout << endl;

    }
    return 0;
}