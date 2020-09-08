#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k;
string s, f;
bool r;
ulli m[207][207][207];
bool mi[207][207][207];

ulli solve(int i, int ki, int fi){
    if(i == n) return 0;
    if(mi[i][ki][fi]) return m[i][ki][fi];
    mi[i][ki][fi] = true;
    ulli ans = 0;
    if(s[i] == f[0]) ans = solve(i + 1, ki, fi + 1) + (r ? fi : 0);
    else if(ki > 0) ans = solve(i + 1, ki - 1, fi + 1) + (r ? fi : 0);

    if(s[i] == f[1]) ans = max(fi + solve(i + 1, ki, r ? fi + 1 : fi), ans);
    else if(ki > 0) ans = max(fi + solve(i + 1, ki - 1, r ? fi + 1 : fi), ans);
    
    ans = max(solve(i + 1, ki, fi), ans);
    m[i][ki][fi] = ans;
    return ans;
}

int main(){
    cin >> n >> k;
    cin >> s >> f;
    r = (f[0] == f[1]);
    cout << solve(0, k, 0) << endl;
    return 0;
}