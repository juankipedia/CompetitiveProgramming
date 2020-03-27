# include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;

ulli mod = 998244353;
ulli n, k, p[200000], pos[200000];

int main(){
    cin >> n >> k;
    ulli sm = 0;
    ulli j = 0;
    for(ulli i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] > (n - k)){
            sm = (sm % mod + p[i] % mod) % mod;
            pos[j] = i; 
            j++;
        }
    }
    ulli r = 1;
    for(ulli i = 1; i < j; i ++) r = (r % mod * (pos[i] - pos[i - 1]) % mod) % mod;
    cout << sm << " " << r << endl;
    return 0;
}