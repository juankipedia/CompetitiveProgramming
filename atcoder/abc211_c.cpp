# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const lli MOD = 1e9 + 7;
const string p = "chokudai";
string s;
int n, m = 8;
lli dp[100005][10];

lli go(int i, int j){
    if(j >= m) return 1;
    if(i >= n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    lli ans = 0;
    if(s[i] == p[j]) ans = go(i + 1, j + 1);
    return dp[i][j] = ans = (ans + go(i + 1, j)) % MOD;
}

int main(){
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
    return 0;
}