# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
# define GET(c) ulli(c - 'A')
const int MOD = 998244353;
int N;
string s;

lli dp[1005][4096][11];

lli go(int i, ulli msk, int l){
    if(i >= N) return (msk == 0) ? 0 : 1;
    if(dp[i][msk][l] != -1) return dp[i][msk][l];
    if(((1ULL << GET(s[i])) & msk) && GET(s[i]) != l) return dp[i][msk][l] = go(i + 1, msk, l);
    return dp[i][msk][l] = (go(i + 1, msk | (1ULL << GET(s[i])), GET(s[i])) + go(i + 1, msk, l)) % MOD;
}

int main(){
    io_boost;
    cin >> N >> s;
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, GET('K')) << endl;
    return 0;
}