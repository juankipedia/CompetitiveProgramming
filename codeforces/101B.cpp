# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MOD = 1000000007;
int n, m; 
pair<int, int> st[100005];

int main(){
    cin >> n >> m;
    map<int, int> c;
    c[0];
    c[n];
    for(int i = 0; i < m; i++) 
        cin >> st[i].first >> st[i].second,
        c[st[i].first], c[st[i].second];
    
    int id = 0;
    for(auto &p: c) p.second = ++id;

    lli dp[id + 5] = {0};
    vector<int> g[id + 5];
    dp[1] = 1;
    for(int i = 0; i < m; i++) g[c[st[i].second]].push_back(c[st[i].first]);
    for(int i = 2; i <= id; i++){
        lli ans = 0;
        for(auto it: g[i]) ans += dp[i -1 ] - dp[it - 1];
        ans = (ans % MOD + MOD) % MOD;
        
        dp[i]= (dp[i - 1] + ans) % MOD;
    }
    cout<<((dp[id] - dp[id - 1]) % MOD + MOD) % MOD << endl;
    return 0;
}