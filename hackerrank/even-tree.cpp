#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100;
int N, M, cnt[MAXN], ans;
vector<int> g[MAXN];
int count(int u, int p){
    cnt[u] = 1;
    for(int v: g[u])
        if(v != p) cnt[u] += count(v, u);
    if(cnt[u] % 2 == 0) ans ++; 
    return cnt[u];
}

int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    count(0, 0);
    cout << ans - 1 << endl;
    return 0;
}
