# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli t, n, a[200005], s[200005], s2[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        s[0] = 0;
        lli f[100000] = {0};
        for(int i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
        s2[0] = f[0];
        for(int i = 1; i <= 1e4; i++){
            s[i] = f[i] * i + s[i - 1];
            s2[i] = f[i] + s2[i - 1];
        }
        if(f[0] == n){
            cout << 0 << endl;
            continue;
        }
        int ans = 1e9, N = 1e4;
        s[N + 1] = s[N];
        s2[N + 1] = s2[N];
        for(int i = 1e4; i >= 1; i--){
            lli rsum = s[N + 1] - s[i], lsum = s[i - 1];
            int r = s2[N + 1] - s2[i], l = s2[i - 1];
            lli rs = r * i, ls = l * i; 
            lli offset = rsum - rs, need = ls - lsum;
            if(offset == need) ans = min(r, ans);
        }
        if(ans == 1e9) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}