# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 5005;
int n;
lli a[MAXN], b[MAXN], s[MAXN], dp[MAXN][MAXN];

lli go(int i, int j) {
    if(j < i) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    lli ans;
    if(i == j) ans = a[i] * b[i];
    else ans = a[i] * b[j] + a[j] * b[i] + go(i + 1, j - 1);
    return dp[i][j] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    s[0] = 0;
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + a[i] * b[i];
    memset(dp, -1, sizeof(dp));
    lli ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            ans = max(ans, s[i] + (s[n] - s[j + 1]) + go(i, j));
        }

    cout << ans << endl;

    return 0;
}