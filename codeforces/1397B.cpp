#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ull;
typedef long long int ll;

ll a[100000], n;

ll pow(ll n, ll e){
    ll res { 1 };
    while(e > ll(0)){
      if (e & 1)
        res = res * n;
      e >>= 1;
      n = n * n;
    }
    return res;
}

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n >= 64){
        ull ans = 0;
        for(int i = 0; i < n; i++) ans += a[i] - 1;
        cout << ans;
    }
    else{
        sort(a, a + n);
        ull ans = numeric_limits<ull>::max();
        ll c = 1;
        while (pow(c, n - 1) < a[n - 1]){
            ull ansi = 0;
            for(int i = 0; i < n; i++) ansi += abs(pow(c, i) - a[i]);
            ans = min(ansi, ans); 
            c++;
        }
        ull ansi = 0;
        for(int i = 0; i < n; i++) ansi += abs(pow(c, i) - a[i]);
        ans = min(ansi, ans); 
        cout << ans << endl;
    }
    
    return 0;
}