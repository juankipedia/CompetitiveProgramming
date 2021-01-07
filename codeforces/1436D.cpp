#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 200005;
int N, leaf[MAXN];
vector<int> g[MAXN];
lli ans, a[MAXN];

void dfs(int v){
    leaf[v] = (g[v].size()) ? 0 : 1;
    for(int u: g[v]){
        dfs(u);
        a[v] += a[u];
        leaf[v] += leaf[u];
    }
    ans = max((a[v] + leaf[v] - 1) / leaf[v], ans);
}

int main(){
    cin >> N;
    for(int i = 1, pi; i < N; i++) cin >> pi, g[--pi].push_back(i);
    for(int i = 0; i < N; i++) cin >> a[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}