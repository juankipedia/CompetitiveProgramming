#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli l, r, a, a2;

int main(){
    cin >> t;
    while(t--){
        cin >> l >> r;
        if(l % (r + 1) < ((r + 1) % 2 ? (r + 1) / 2 + 1 : (r + 1) / 2 )) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}