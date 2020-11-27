#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, q, l, r;
string s;

int memo[100][100][2];

bool dp(int i, int j, bool f){
    if(j > r) return f;
    if(i >= n) return false;
    bool ans = false;
    if(memo[i][j][f] != -1) return memo[i][j][f];
    if(s[i] == s[j]){
        ans = ans || dp(i + 1, j + 1, f);
    }
    ans = ans || dp(i + 1, j, j > l);
    memo[i][j][f] = ans;
    return ans;
}
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> q >> s;
        for(int i = 0; i < q; i++){
            cin >> l >> r;
            memset(memo, -1, sizeof(memo));
            l--; r--;
            if(r == l) cout << "NO" << endl;
            else{
                if(dp(0, l, false)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
    return 0;
}