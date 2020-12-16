#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        lli ans = 0;
        for(int i = 0; i < n - 2; i++){
            lli pos = upper_bound(a, a + n, a[i] + 2) - a;
            pos --;
            //cout << "----"  << pos << endl;
            pos = pos - i - 1;
            ans += pos * (pos + 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}