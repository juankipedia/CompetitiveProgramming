# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[400005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        lli ans = 0;
        a[0] = a[n + 1] = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                ans += a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
        //cout << ans << endl;
        for(int i = 1; i <= n + 1; i++){
            //cout << a[i] << " ";
            ans += abs(a[i] - a[i - 1]);
        }
        //cout << endl;
        cout << ans << endl;
    }
    return 0;
}