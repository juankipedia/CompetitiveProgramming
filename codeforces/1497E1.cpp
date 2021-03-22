# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N, k, a[200005];

int prime_factors(int n){
    int cnt = 0, ret = 1;
    while(n % 2 == 0) cnt++, n = n/2;
    if(cnt % 2) ret *= 2;
    for(int i = 3; i * i <= n; i = i + 2){
        cnt = 0;
        while(n % i == 0) cnt++, n = n/i;
        if(cnt % 2) ret *= i;
    }    
    if(n > 2) ret *= n;
    return ret;
}

int main(){
    cin >> t;
    while(t--){
        cin >> N >> k;
        for(int i = 0; i < N; i++) cin >> a[i];
        set<int> s;
        int ans = 0;
       
        for(int i = 0; i < N; i++){
            int p = prime_factors(a[i]);
            if(s.count(p)){
                ans++;
                s.clear();
            }
            s.insert(p);
        }
        ans++;
        cout << ans << endl;
    }
    return 0;
}