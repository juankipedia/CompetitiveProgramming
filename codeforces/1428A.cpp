#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli X1, X2, Y1, Y2;

int main(){
    cin >> t;
    while(t--){
        cin >> X1 >> Y1 >> X2 >> Y2;
        lli ans = abs(X2 - X1);
        if(Y1 != Y2 && X2 != X1) ans += 2;
        ans += abs(Y1 - Y2);
        cout << ans << endl;
    }
    return 0;
}