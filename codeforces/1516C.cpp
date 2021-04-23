# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, a[105], total;
int dp[105][200005];

int go(int i, int sum){
    if(i >= n){
        if(total - sum  == sum) return sum;
        else return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = max(go(i + 1, sum + a[i]), go(i + 1, sum));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], total += a[i];
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0);
    if(ans){
        cout << 1 << endl;
        int ans = -1;
        for(int p = 2; p <= 2000; p *=2){
            for(int i = 0; i < n; i++){
                if(a[i] % p != 0){
                    ans = i + 1;
                    break;
                }
            }
            if(ans != -1) break;
        }
        if(ans != -1) cout << ans << endl;
        else cout << 1 << endl;
    }
    else cout << 0 << endl;
    return 0;
}