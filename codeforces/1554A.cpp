# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int t, n;
lli a[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        lli ans = 0;
        for(int i = 1; i < n - 1; i++)
            ans = max({ans, a[i] * a[i - 1], a[i] * a[i + 1]});
        ans = max({ans, a[0] * a[1], a[n - 1] * a[n - 2]});
        cout << ans << endl;
    }
    return 0;
}