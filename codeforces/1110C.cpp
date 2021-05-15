# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int q;
ulli a;

int divisors(int n){
    int maxi = 0;
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
            maxi = max({maxi, i, (n / i == n) ? 0 : n / i});
    return maxi;
}

int main(){
    cin >> q;
    while(q--){
        cin >> a;
        ulli b = 0;
        for(ulli i = 0; i < 25; i++)
            if(a & (1 << i)) continue;
            else if((b | (1 << i)) < a) b = b | (1 << i);
        if(b == 0) cout << divisors(a) << endl;
        else cout << (a ^ b) << endl;
    }
    return 0;
}