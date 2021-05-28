# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = 2000 * 1e9 + 5;
int n, a[2005];
lli dp[2005][2005];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) dp[0][i] = -oo;
    dp[0][1] = a[0] < 0 ? -oo : a[0]; 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i < n; i++){
            lli ansi = dp[i - 1][k - 1] + a[i];
            dp[i][k] = max(dp[i - 1][k], ansi < 0 ? -oo : ansi);
        }
    }
    int ans = 0;
    for(int k = n; k >= 0; k--)
        if(dp[n - 1][k] >= 0){ 
            ans = k; 
            break; 
        }
    cout << ans << endl;
}