# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const lli oo = 1e15;
int n, k, x, a[205];
lli dp[205][205];
bool dpb[205][205];

lli go(int i, int xi){
    if(i >= n){
        if(xi != x) return -oo;
        else return 0;
    }
    if(dpb[i][xi]) return dp[i][xi];
    dpb[i][xi] = true;
    lli ans = -oo;
    lli s = 0;
    for(int j = 0; j < k && (i + j) < n; j++){
        s += a[i + j];
        for(int l = 1; l <= k; l++)
            ans = max(ans, s + go(i + j + l, xi + 1 + j));
    }
    return dp[i][xi] = ans;
}

int main(){
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    lli ans = -oo;
    for(int i = 0; i < k; i++) ans = max(ans, go(i, 0));
    if(ans < 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}