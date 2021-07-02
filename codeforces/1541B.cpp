# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        lli ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = (a[i] - i % a[i]); j < i; j += a[i])
                if(a[i] * a[j] == i + j) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}