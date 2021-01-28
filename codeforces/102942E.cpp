#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli MOD = 1e9 + 7;
int t, n;
string s;
lli m[100000][10];

lli dp(int i, char l){
    if(i >= n) return 1;
    if(s[i] != '-' && s[i] < l) return 0;
    if(m[i][l - '0'] != -1) return m[i][l - '0'];
    if(s[i] != '-') return m[i][l - '0'] = dp(i + 1, s[i]);
    lli ans = 0; 
    for(int j = l - '1'; j < 9; j++)
        ans = (ans +  dp(i + 1, '1' + j)) % MOD;
    return m[i][l - '0'] = ans;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        memset(m, -1, sizeof(m));
        cout << dp(0, '1') << endl;
    }
    return 0;
}