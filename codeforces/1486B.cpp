#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli x[1000], y[1000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        sort(x, x + n);
        sort(y, y + n);
        n--;
        lli xi = x[(n + 1) / 2] - x[n / 2] + 1;
        lli yi = y[(n + 1) / 2] - y[n / 2] + 1;
        cout << xi * yi << endl;
    }
    return 0;
}