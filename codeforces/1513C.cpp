# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
const int MOD = 1e9 + 7;
lli memo[200005];
string n;

lli dp(lli m){
    if(m < 0) return 1;
    if(memo[m] != -1) return memo[m];
    return memo[m] = (dp(m - 9) % MOD + dp(m - 10) % MOD) % MOD;
}


int main(){
    io_boost;
    memset(memo, -1, sizeof(memo));
    dp(2e5 + 5);
    for(int i = 0; i <=  2e5 + 5; i++){
        if(memo[i] == -1) dp(i);
    }
    cin >> t;
    int m;
    while(t--){
        cin >> n >> m;
        lli ans = 0;
        for(int i = 0; i < n.size(); i++){
            ans = (ans + dp(m - (10 - (n[i] - '0')))) % MOD;
        }
        cout << ans << endl;
    }
    //cout << dp(92) + dp(91) << endl;
    return 0;
}