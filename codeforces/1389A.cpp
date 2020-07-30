#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli l, r;

int main(){
    cin >> t;
    while (t--){
        cin >> l >> r;
        if(2 * l <= r) cout << l << " " << 2 * l << endl;
        else cout << -1 << " " << -1 << endl;
    }
    
    return 0;
}