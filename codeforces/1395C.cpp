#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m;
lli a[200], b[200];
lli dp[200][1026];

lli f(int i, lli ac){
    if(i >= n)
        return ac;
    if(dp[i][ac] != -1) return dp[i][ac];
    lli ans  = numeric_limits<lli>::max();
    for(int j = 0; j < m; j++)
        ans = min((f(i + 1, ac | (a[i] & b[j]))), ans);
    return dp[i][ac] = ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < 200; i ++)
        for(int j = 0; j < 1026; j++)
            dp[i][j] = -1;
    cout << f(0, 0) << endl;
    return 0;
}