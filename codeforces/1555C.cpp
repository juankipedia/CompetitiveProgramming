# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
 
int t, m;
lli g[100005][2], s[1000005][2];
 
int main(){
    cin >> t;
    while(t--){
        cin >> m;
        s[0][0] = s[0][1] = 0;
        for(int i = 0; i < m; i++) 
            cin >> g[i][0], 
            s[i + 1][0] = s[i][0] + g[i][0];
        for(int i = 0; i < m; i++)
            cin >> g[i][1], 
            s[i + 1][1] = s[i][1] + g[i][1];
        lli ans = numeric_limits<lli>::max(), sa = 0;
        for(int i = 0; i < m; i++)
            ans = min(max(s[i][1], s[m][0] - s[i + 1][0]), ans);
        cout << ans << endl;
    }
    return 0;
}