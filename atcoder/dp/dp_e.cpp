# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli oo = 1e18 + 5;
lli N, W, v[105], w[105];
lli dp[100005]; 

int main(){
    cin >> N >> W;
    lli sum = 0;
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    for(int val: v) sum += val;
    for(int i = 1; i <= sum; i++) dp[i] = oo;
    for(int i = 0; i < N; i++)
        for(int j = sum - v[i]; j >= 0; j--)
            dp[j + v[i]] = min(dp[j + v[i]], w[i] + dp[j]);
    int ans = 0;
    for(int i = 0; i <= sum; i++)
        if(dp[i] <= W) ans = i;
    cout << ans << endl;
    return 0;
}