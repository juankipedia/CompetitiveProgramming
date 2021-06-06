# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int k, q, n;
string t, c;
lli dp[1000000];

lli build(int u){
    if(u > (n - 1 - (1 << (k - 1)))) return dp[u];
    lli L = build((2 * u) + 1), R = build((2 * u) + 2);
    if(t[u] == '?') return dp[u] = L + R;
    else if(t[u] == '1') return dp[u] = L;
    else return dp[u] = R;
}

int main(){
    io_boost;
    cin >> k >> t >> q;
    n = (1 << k) - 1;
    reverse(t.begin(), t.end());

    for(int i = 0; i < (1 << (k - 1)); i++)
        if(t[n - 1 - i] == '?') dp[n - 1 - i] = 2;
        else dp[n - 1 - i] = 1;

    build(0);
    while(q--){
        int p;
        cin >> p >> c;
        p = n - p;
        if(p > n - 1 - (1 << (k - 1))){
            if(c == "?") dp[p] = 2;
            else dp[p] = 1;
        }
        else{
            if(c == "?") dp[p] = dp[(2 * p) + 1] + dp[(2 * p) + 2];
            else if(c == "1") dp[p] = dp[(2 * p) + 1];
            else dp[p] = dp[(2 * p) + 2];
        }
        t[p] = c[0];
        
        p = (p - 1) / 2;

        while(p != 0){
            if(t[p] == '?') dp[p] = dp[(2 * p) + 1] + dp[(2 * p) + 2];
            else if(t[p] == '1') dp[p] = dp[(2 * p) + 1];
            else dp[p] = dp[(2 * p) + 2];
            p = (p - 1) / 2;
        }
        if(t[p] == '?'){
            if((2 * p) + 2 < n) dp[p] = dp[(2 * p) + 1] + dp[(2 * p) + 2];
        }
        else if(t[p] == '1'){
            if((2 * p) + 1 < n) dp[p] = dp[(2 * p) + 1];
        }
        else{
            if((2 * p) + 2 < n) dp[p] = dp[(2 * p) + 2];
        }
        cout << dp[0] << endl;
    }
    return 0;
}