#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli x, y, k;

int main(){
    cin >> t;
    while(t--){
        cin >> x >> y >> k;
        ulli v = y * k + k - 1, w = x - 1;
        ulli a = (v + w - 1) / w;
        cout << a + k << endl;
    }
    return 0;
}