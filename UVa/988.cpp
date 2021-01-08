#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int N;

lli dp(vector<int> g[], lli m[], int u){
    if(m[u] != -1) return m[u];
    if(!g[u].size()) m[u] = 1;
    else m[u] = 0;
    for(int v: g[u]) m[u] += dp(g, m, v);
    return m[u];
}

int main(){
    io_boost;
    bool f = true;
    while(cin >> N){
        if(f) f = false;
        else cout << endl;
        vector<int> g[N];
        lli m[N];
        memset(m, -1, sizeof(m));
        for(int i = 0, n; i < N; i++){
            cin >> n;
            for(int j = 0, k; j < n; j++) cin >> k, g[i].push_back(k);
        }
        cout << dp(g, m, 0) << endl;   
    }
    return 0;
}