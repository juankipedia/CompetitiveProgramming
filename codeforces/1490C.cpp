#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli x;

bool check(ulli b3){
    while(b3 != 1){
        if(b3 % 3) return false;
        b3 /= 3;
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> x;
        bool ok = false;
        for(ulli a = 1; (a * a * a) < x; a++){
            ulli b3 = x - (a * a * a);
            ulli b = cbrt(b3);
            if((b * b * b) == b3){
                ok = true;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}