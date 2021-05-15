# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int oo = 1e9 + 5;
int H, W, dp[2005][2005], dpb[2005][2005], ii[] = {0, 1}, jj[] = {1, 0};
string m[2005];

int go(int i, int j){
    if(i == H - 1 && j == W - 1) return 0;
    if(dpb[i][j]) return dp[i][j];
    dpb[i][j] = true;
    bool t = ((i + j) % 2) == 0;
    int ans = t ? -oo : oo;
    for(int l = 0; l < 2; l++){
        int ni = ii[l] + i, nj = jj[l] + j;
        if(ni < H && nj < W){
            if(t) ans = max(ans, go(ni, nj) + ((m[ni][nj] == '+') ? 1 : -1));
            else ans = min(ans, go(ni, nj) + ((m[ni][nj] == '+') ? -1 : 1));
        }
    }
    return dp[i][j] = ans;
}

int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++) cin >> m[i];
    go(0, 0);
    if(dp[0][0] > 0) cout << "Takahashi" << endl;
    else if(dp[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}