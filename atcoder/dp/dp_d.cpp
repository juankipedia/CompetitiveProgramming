# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, W;
lli dp[105][100005], v[105], w[105];

lli go(int i, lli wi){
    if(i >= N) return 0;
    lli &ans = dp[i][wi];
    if(ans != -1) return ans;
    ans = 0;
    if(w[i] + wi <= W) ans = v[i] + go(i + 1, w[i] + wi);
    ans = max(go(i + 1, wi), ans);
    return ans;
}

int main(){
    cin >> N >> W;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    cout << go(0, 0) << endl;
    return 0;
}