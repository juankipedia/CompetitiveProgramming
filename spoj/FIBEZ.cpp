#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli m[500005];

lli fibonacci(lli n, lli mod){
    if(m[n] != -1) return m[n];
    lli fn2 = 0, fn1 = 1;
    for(lli i = 2; i <= n; i++){
        lli a = fn1;
        fn1 = (fn1 % mod + fn2 % mod) % mod;
        m[i] = fn1;
        fn2 = a;
    }
    return m[n];
}

int main(){
    io_boost;
    int t;
    memset(m, -1, sizeof(m));
    m[0] = 0;
    m[1] = 1;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        cout << fibonacci(n, 1e8 + 7) << endl;
    }
    return 0;
}