#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a < b) swap(a, b);
        lli r = a % b;

        lli ans  = a / b;
        //cout << r << endl;
        ans = (b * (ans - 1));
        r += ans % 10;
        ans /= 10;
        //cout << ans % 10 << endl;
        if(r % 10) r = r / 10 + 1;
        else r /= 10;
        ans += r;
        cout << ans << endl;

    }
    return 0;
}