# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int lst[105][26], n;
lli k, dp[105][105];
string s;

int main(){
    cin >> n >> k >> s;
    memset(lst, -1, sizeof(lst));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 26; j++) {
			if(i > 0) lst[i][j] = lst[i - 1][j];
		}
		lst[i][s[i] - 'a'] = i;
	}
    k--;
    for(int i = 0; i < n; i++) dp[i][1] = 1;
    for(int j = 2; j < n; j++)
        for(int i = 1; i < n; i++)
            for(int k = 0; k < 26; k++)
                if(lst[i - 1][k] != -1) 
                    dp[i][j] = min(lli(1e12), dp[i][j] + dp[lst[i - 1][k]][j - 1]);

    lli ans = 0;
    for(int i = n - 1; i >= 1; i--){
        lli cnt = 0;
        for(int j = 0; j < 26; j++)
            if(lst[n - 1][j] != -1) cnt += dp[lst[n - 1][j]][i];
        cnt = min(cnt, lli(1e12));
        if(cnt >= k){
            ans += k * (n - i);
            k = 0;
            break;
        }
        ans += cnt * (n - i);
        k -= cnt;
    }
    if(k == 1) ans += n, k--;
    if(k > 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}