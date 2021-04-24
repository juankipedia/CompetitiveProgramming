# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
long double p[3005], dp[3005][3005];

long double f(int i, int heads){
    if(i < 0){
        if(heads == 0) return 1;
        else return 0;
    }
    if(heads > (i + 1)) return 0;
    if(dp[i][heads] != -1) return dp[i][heads];
    return dp[i][heads] = p[i] * f(i - 1, heads - 1) + (1.0 - p[i]) * f(i - 1, heads);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    for(int i = 0; i < n; i++) cin >> p[i];
    long double ans = 0;
    for(int i = (n + 1) / 2; i <= n; i++)
            ans += f(n - 1, i);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}