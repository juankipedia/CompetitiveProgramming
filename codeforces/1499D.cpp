# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAXN = 2e7 + 5;
int f[MAXN], cnt[MAXN], t, c, d, x;
 
int main(){
    io_boost;
    cin >> t;
    memset(f, -1, sizeof(f));
    for(int i = 2; i < MAXN; ++i)
        if(f[i] == -1)
            for(int j = i; j < MAXN; j += i) 
                if(f[j] == -1)
                    f[j] = i;
    for(int i = 2; i < MAXN; ++i) {
        int j = i / f[i];
        cnt[i] = cnt[j] + (f[i] != f[j]);
    }
 
    while(t--){
        cin >> c >> d >> x;
        lli ans = 0;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(x / i != i)
                    if((x / (x / i) + d) % c == 0) ans += (1LL << cnt[(x / (x / i) + d) / c]);
                if((x / i + d) % c == 0) ans += (1LL << cnt[(x / i + d) / c]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
