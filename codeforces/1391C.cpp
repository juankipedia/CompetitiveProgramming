#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli MOD = 1e9+7;
lli n;

lli fact_n_mod_p(lli n, lli p){ 
    if (n >= p) 
        return 0; 
  
    lli result = 1; 
    for (lli i = 1; i <= n; i++) 
        result = (result * i) % p; 
  
    return result; 
} 
  
lli binpow(lli a, lli b){
	if(b == 0) return 1;
	if(b&1) return a * binpow(a, b-1) % MOD;
	return binpow(a * a % MOD, b >> 1);
}
 
int main(){
    cin >> n;
    lli ans = fact_n_mod_p(n, MOD) % MOD - binpow(2, n - 1) % MOD;
    ans += MOD;
    cout << (ans) % MOD << endl; 
    return 0;
}