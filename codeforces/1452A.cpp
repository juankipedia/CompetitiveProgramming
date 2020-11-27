#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, x, y;

int main(){
    cin >> t;
    while(t--){
        cin >> x >> y;
        if(x == 0 && y == 0) cout << 0 << endl;
        else if(abs(x - y) <= 1) cout << x + y << endl;
        else cout << 2 * min(x, y) + 2 * (max(x, y) - min(x,y)) - 1 << endl;
    }
    return 0;
}