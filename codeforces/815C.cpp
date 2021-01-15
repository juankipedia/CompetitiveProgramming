#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int MAXN = 5005;
int N, cnt[MAXN];
lli b, c[MAXN], d[MAXN], dp[MAXN][MAXN][2];
vector<int> g[MAXN];

void dfs(int u){
    cnt[u] = 1;
    dp[u][1][0] = c[u];
    dp[u][1][1] = c[u] - d[u];
    dp[u][0][0] = 0;
    for(int v : g[u]){
        dfs(v);
        for(int j = cnt[u]; j >= 0; j--){
            for(int i = 0; i <= cnt[v]; i++){
                dp[u][i + j][0] = min(dp[u][i + j][0], dp[v][i][0] + dp[u][j][0]);
                dp[u][i + j][1] = min(dp[u][i + j][1], min(dp[v][i][1], dp[v][i][0]) + dp[u][j][1]);
            }
        }
        cnt[u] += cnt[v];
    }
}

int main(){
    io_boost;
    cin >> N >> b;
    cin >> c[0] >> d[0];
    for(int i = 1, u; i < N; i++){
        cin >> c[i] >> d[i] >> u;
        u--;
        g[u].push_back(i);
    }
    memset(dp, 17, sizeof dp);
    int ans = N;
    dfs(0);
    while(ans >= 0 && dp[0][ans][1] > b && dp[0][ans][0] > b) ans--;
    cout << ans << endl;
    return 0;
}