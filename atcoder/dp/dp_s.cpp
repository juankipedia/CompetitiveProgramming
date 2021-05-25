# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXL = 10000 + 7, MAXS = 105, MOD = 1e9 + 7;
int l, D, N[MAXL];
lli dp[MAXL][2][MAXS][2];

lli go(int i, int t, int sum, int nz){
    if(i >= l){
        if(nz && !sum) return 1;
        else return 0;
    }
    if(dp[i][t][sum][nz] != -1) return dp[i][t][sum][nz];
    lli ans = 0;
    for(int j = 0; j <= ( t ? N[i] : 9); j++)
        ans = (ans + go(i + 1, (t && (j == N[i])) ? 1 : 0, (sum + j) % D, j ? 1 : nz)) % MOD;
    return dp[i][t][sum][nz] = ans;
}

int main(){
    string K;
    cin >> K >> D;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < K.size(); i++) N[i] = K[i] - '0';
    l = K.size();
    cout << go(0, 1, 0, 0) << endl;
    return 0;
}