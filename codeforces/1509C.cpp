# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
lli s[2005];
lli dp[2005][2005];

lli go(int i, int j){
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = min(go(i + 1, j), go(i, j - 1)) + s[j] - s[i];
    return dp[i][j];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    memset(dp, -1, sizeof(dp));

    cout << go(0, n - 1) << endl;
    return 0;
}