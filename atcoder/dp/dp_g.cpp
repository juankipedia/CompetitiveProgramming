# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N, M, dp[MAXN];
vector<int> g[MAXN];

int go(int i){
    if(dp[i] != -1) return dp[i];
    dp[i] = 0;
    for(int j : g[i])
        dp[i] = max(1 + go(j), dp[i]);
    return dp[i];
}

int main(){
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for(int i = 0, x, y; i < M; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, go(i));
    cout << ans << endl;
    return 0;
}