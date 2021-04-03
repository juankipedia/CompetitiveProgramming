# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, k;
const lli MOD = 998244353;
lli memo[2005][2005];

lli dp(int i, int ki){
    if(i >= n) return ki == k;
    if(memo[i][ki] != -1) return memo[i][ki];
    lli ans = 0;
    if(ki < k) ans = (ans +  ((m - 1) * dp(i + 1, ki + 1)) % MOD) % MOD;
    ans = (ans + dp(i + 1, ki)) % MOD; 
    return memo[i][ki] = ans;
}

int main(){
    cin >> n >> m >> k;
    memset(memo, -1, sizeof(memo));
    cout << (m * dp(1, 0))% MOD << endl;
    return 0;
}