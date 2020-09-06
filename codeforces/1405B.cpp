#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli p[100000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        lli ans = 0;
        for(int i = 0; i < n; i++){
            if(p[i] > 0) ans += p[i];
            else if(p[i] < 0){
                lli d = min(-p[i], ans);
                p[i] += d;
                ans -= d;
            }
        }
        cout << ans << endl;
    }
    return 0;
}