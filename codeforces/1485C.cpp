#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli x, y;

int main(){
    cin >> t;
    while(t--){
        cin >> x >> y;
        lli ans = 0;
        for(lli k = 1; k * k <= x; k++)
            ans += max(0LL, min(y, x / k - 1 ) - k);
        cout << ans << endl;
    }
    return 0;
}