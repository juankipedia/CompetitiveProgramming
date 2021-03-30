# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli MOD = 1e9 + 7;
int t, n, k;
lli memo[1005][1005][2];

lli solve(int p, int ki, int r){
    if(p == 0 || p == n + 1) return 0;
    if(ki == 1) return 0;
    if(memo[p][ki][r] != -1) return memo[p][ki][r];
    int ans;
    if(r) ans = (solve(p + 1, ki, 1) % MOD + solve(p - 1, ki - 1, 0) % MOD + 1) % MOD;
    else ans = (solve(p - 1, ki, 0) % MOD + solve(p + 1, ki - 1, 1) % MOD + 1) % MOD;
    return memo[p][ki][r] = ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < 1005; i++)
            for(int j = 0; j < 1005; j++)
                for(int k = 0; k < 2; k++)
                    memo[i][j][k] = -1;
        cout << solve(1, k, 1)  + 1 << endl;
    }
    return 0;
}