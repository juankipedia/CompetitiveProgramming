# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int prime_factors(int n){
    int res = 0;
    while(n % 2 == 0) res++, n = n / 2;  
    for(int i = 3; i * i <= n; i = i + 2)  
        while(n % i == 0) res++, n = n / i;
    if(n > 2) res++;
    return res;
}

int t, a, b, k;

int main(){
    io_boost;
    cin >> t;
    int kkk = 1;
    while(t--){
        cin >> a >> b >> k;
        if(a > b) swap(a, b);
        int gcd = __gcd(a, b), ca = 0, cb = 0, cgcd = 0;

        if(a / gcd != 1) ca = prime_factors(a / gcd);
        if(b / gcd != 1) cb = prime_factors(b / gcd);
        
        cgcd = prime_factors(gcd) * 2;
        if(k == 1 && (gcd != a || a == b)){
            cout << "NO" << endl;
            continue;
        }
        if((ca + cb + cgcd) < k) cout << "NO" << endl;
        else cout << "YES" << endl;
        kkk++;
    }
    return 0;
}