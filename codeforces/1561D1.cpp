# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n, MOD;
lli dp[200005];

int main(){
    cin >> n >> MOD;
    dp[1] = 1;
    lli sum = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = sum;
        for(int j = 2; j * j <= i; j++) dp[i] = (dp[i] + dp[i / j]) % MOD;
        for(int j = 1; j * j <= i; j++){
            int r = i / j, l = (i / (j + 1)) + 1;
            if(l <= (lli) sqrt(i)) continue;
            dp[i] = (dp[i] + (dp[j] * (r - l + 1)) % MOD) % MOD;
        }
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}