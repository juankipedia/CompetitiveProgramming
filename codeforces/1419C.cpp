#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli t, n, x, a[1000];
int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(lli i = 0; i < n; i++) cin >> a[i];
        bool ok = true, same = false;
        for(lli i = 0; i < n; i++){
            if(a[i] != x) ok =false;
            else same = true;
        }
        if(ok){
            cout << 0 << endl;
            continue;
        }
        lli s = 0;
        for(lli i = 0; i < n; i++)
            if(a[i] > x) s += x - a[i];
            else s += x - a[i];
        
        if(s == 0 || same) cout << 1 << endl;
        else cout << 2 << endl;
        
    }
    return 0;
}