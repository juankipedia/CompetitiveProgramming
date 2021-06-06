# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        map<pair<int, int>, int> dp;
        int D = 0, K = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'D') D++;
            else K++;
            int gcd = __gcd(D, K);
            auto f = make_pair(D / gcd, K / gcd);
            dp[f] = dp[f] + 1;
            cout << dp[f] << " ";
        }
        cout << endl;
    }
    return 0;
}