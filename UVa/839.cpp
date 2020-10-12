#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
bool ok;

lli f(){
    lli wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    if(wl == 0) wl = f();
    if(wr == 0) wr = f();
    if((wl * dl) != (wr * dr)) ok = false;
    return wl + wr;
}

int main(){
    io_boost;
    cin >> n;
    while(n--){
        ok = true;
        auto res = f();
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
        if(n) cout << endl;
    }
    return 0;
}