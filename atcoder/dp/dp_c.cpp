# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int v[MAXN][4], N, dp[MAXN][4];

int go(int i, int l){
    if(i >= N) return 0;
    if(dp[i][l] != -1) return dp[i][l];
    int &ans = dp[i][l];
    ans = 0;
    for(int j = 1; j <= 3; j++)
        if(j != l) ans = max(ans, v[i][j] + go(i + 1, j));
    return ans;
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> v[i][1] >> v[i][2] >> v[i][3];
    cout << go(0, 0) << endl;
    return 0;
}