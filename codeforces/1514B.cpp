# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const ulli MOD = 1e9 + 7;

ulli mypow(ulli n, ulli e){
    n = n % MOD;
    ulli res = 1;
    while(e > 0ULL){
      if (e & 1) res = (res * n) % MOD;
      e >>= 1;
      n = (n * n) % MOD;
    }
    return res;
}

int main(){
    int t, n, k; 
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << mypow(n, k) << endl; 
    }
    return 0;
}