# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100005;
const lli MOD = 1e9 + 7;
int N, K;
lli dp[MAXN];

int main(){
    io_boost;
    cin >> N >> K;
    int ai;
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> ai;
        lli st[K + 5] = {0};
        for(int ki = K; ki >= 0; ki--){
            int l = ki + 1, r = ki + min(ai, K - ki) + 1;
            if(l <= r){
                st[l] = (st[l] + dp[ki]) % MOD; 
                st[r] = (st[r] - dp[ki] + MOD) % MOD;
            }
        }
        lli sum = 0;
        for(int j = 0; j <= K; j++){
            sum = (sum + st[j]) % MOD;
            dp[j] = (dp[j] + sum) % MOD;
        }
    }
    cout << dp[K] << endl;
    return 0;
}