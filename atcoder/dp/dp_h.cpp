# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAX = 1005, MOD = 1e9 + 7;
int H, W, ii[] = {0, 1}, jj[] = {1, 0};
string m[MAX];
lli dp[MAX][MAX];

lli go(int i, int j){
    if(i == H - 1 && j == W - 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    lli ans = 0;
    for(int k = 0; k < 2; k++){
        int ni = ii[k] + i, nj = jj[k] + j;
        if(ni < H && nj < W && m[ni][nj] != '#')
            ans = (ans + go(ni, nj)) % MOD;
    }
    return dp[i][j] = ans;
}

int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++) cin >> m[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
    return 0;
}