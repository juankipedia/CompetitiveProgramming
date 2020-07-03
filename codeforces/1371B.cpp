#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n, r;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> r;
        ulli w = min(n, r), ans = 0;
        if(w == n)
            w --;
        ans += w * (w + 1) / 2;
        if(r >= n)
            ans ++;
        cout << ans << endl;
    }
    return 0;
}