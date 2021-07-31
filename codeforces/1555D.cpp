# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n, q; 
int ts[6][200005];
string p[] = {"abc", "acb", "bac", "bca", "cab", "cba"}, s;

int main(){
    io_boost;
    cin >> n >> q >> s;
    string patterns[6];
    memset(ts, 0, sizeof(ts));
    for(int i = 0; i < 6; i++){
        patterns[i] = "";
        for(int j = 0; j < n; j += 3) patterns[i] += p[i];
        patterns[i] = patterns[i].substr(0, n);
    }
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++)
            ts[i][j + 1] = ts[i][j] + ((patterns[i][j] != s[j]) ? 1 : 0); 
    //for(int i = 0; i <= n; i++) cout << ts[0][i] << " "; cout << endl;
    while(q--){
        int ans = numeric_limits<int>::max(), l, r;
        cin >> l >> r;
        for(int i = 0; i < 6; i++)
            ans = min(ans, ts[i][r] - ts[i][l - 1]);
        cout << ans << endl;
    }

    return 0;
}