# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
 
const lli MOD = 1e9 + 7;
int t, n, k;
lli sum, dp[200005][2], fact[200005];
lli pow_(lli n, lli e){
    lli res = 1;
    while(e > 0ULL){
      if(e & 1) res = (res * n) % MOD;
      e >>= 1;
      n = (n * n) % MOD;
    }
    return res;
}
lli dvd(lli a, lli b) { return (a * pow_(b, MOD - 2)) % MOD; }
 
 
lli choose(lli n, lli k){ 
    return dvd(fact[n], (fact[k] * fact[n - k]) % MOD);
}
 
lli go(int ki, int g){
    if(ki == -1) return 1;
 
    if(dp[ki][g] != -1) return dp[ki][g];
 
    lli ans = 0;
 
    if(g) ans = (pow_(2, n) * go(ki - 1, 1)) % MOD;
    else{
        if(n % 2) ans = (go(ki - 1, 0) + (sum * go(ki - 1, 0)) % MOD) % MOD;
        else ans = (go(ki - 1, 1) + (sum * go(ki - 1, 0)) % MOD) % MOD;
    }
    return dp[ki][g] = ans;
}
 
int main(){
    cin >> t;
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 200000; i++) fact[i] = (i * fact[i - 1]) % MOD;
    while(t--){
        cin >> n >> k;
        sum = 0;
        for(int i = 0; i <= ((n % 2) ? n - 1 : n - 2); i+=2) sum = (sum + choose(n, i)) % MOD;
        memset(dp, -1, sizeof(dp));
        cout << go(k - 1, 0) << endl;
    }
    return 0;
}