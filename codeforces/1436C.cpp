#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
lli mod = 1e9 + 7, n, x, pos;
lli factorial[10000];
 
void factorialf(){ 
    factorial[1] = factorial[0] = 1;
    for(lli i = 2; i <= n; i++) 
        factorial[i] = (factorial[i - 1] * i % mod) % mod;  
} 
 
int main(){
    cin >> n >> x >> pos;
    lli l = 0, r = n, m, gt = n - x, lt = x - 1, ans = 1;
    factorialf();
    while(l < r){
        m = (l + r) / 2;
        if(pos == m) l = m + 1;
        else if(pos < m){
            ans = (gt % mod * ans % mod) % mod;
            gt--;
            r = m;
        }
        else{
            ans = (lt % mod * ans % mod) % mod;
            lt--;
            l = m + 1;
        }
 
        if(gt < 0 || lt < 0){
            cout << 0 << endl;
            return 0;
        }
    }
    if(l == pos + 1) cout << (ans % mod * factorial[gt + lt] % mod) % mod << endl;
    else cout << 0 << endl;
    return 0;
}