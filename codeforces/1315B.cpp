# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli a, b, p;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> p;
        cin >> s;
        int n = s.size();
        lli dp[n] = {0};
        for(int i = n - 2, j = n - 1; i >= 0; i--){
            if(s[i] != s[i + 1]) j = i + 1;
            dp[i] = dp[j];
            if(s[i] == 'A') dp[i] += a;
            else dp[i] += b;
        }
        int ans = n - 1;
        for(int i = 0; i < n; i++)
            if(dp[i] <= p){
                ans = i + 1;
                break;
            }
        cout << ans << endl;
    }
    return 0;
}