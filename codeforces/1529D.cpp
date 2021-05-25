# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MOD = 998244353;
int n;

int main(){
    cin >> n;
    int prime[n + 1] = {0}; 
     
    for(int p = 1; p <= n; p++){          
        for(int i = p; i <= n; i += p) 
            prime[i]++; 
    } 

    vector<lli> dp(n + 1, 1);
    lli cur = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = (prime[i] + cur) % MOD;
        cur = (cur + dp[i]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}