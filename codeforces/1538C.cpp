# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, l, r, a[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        lli ans = 0;
        for(int i = 0; i < n; i++){
            int L = lower_bound(a, a + n, l - a[i]) - a, R = upper_bound(a, a + n, r - a[i]) - a;
            R--;
            if(i < L) continue;
            if(i == L) L++;
            R = min(R, i - 1);
            if(L > R) continue;
            ans += R - L + 1;
        }
        cout << ans << endl;
    }
    return 0;
}