#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli a1, b1, c1, a2, b2, c2;
lli ans;

int main(){
    cin >> t;
    while(t--){
        ans = 0;
        cin >> a1 >> b1 >> c1;
        cin >> a2 >> b2 >> c2;
        lli f = min(c1, b2);
        ans += f * 2;
        c1 -= f; b2 -= f;
        f = min(a1, c2);
        a1 -= f; c2 -= f;
        f = min(b1, a2);
        b1 -= f; a2 -= f;
        if(c1 != 0 && c2 != 0){
            f = min(c1, c2);
            c1 -= f; c2 -= f;
        }
        if(c1 != 0 && a2 != 0){
            f = min(c1, a2);
            c1 -= f; a2 -= f;
        }

        if(b2 != 0 && a1 != 0){
            f = min(b2, a1);
            b2 -= f; a1 -= f;
        }
        if(b2 != 0 && b1 != 0){
            f = min(b2, b1);
            b2 -= f; b1 -= f;
        }

        if(a1 != 0 && a2 != 0){
            f = min(a2, a1);
            a2 -= f; a1 -= f;
        }

        if(c2 != 0 && b1 != 0){
            f = min(c2, b1);
            c2 -= f; b1 -= f;
            ans -= f * 2;
        }
        cout << ans << endl;
    }
    return 0;
}