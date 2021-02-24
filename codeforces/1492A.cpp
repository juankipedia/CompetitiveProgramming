#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli p, a, b, c;

int main(){
    cin >> t;
    while(t--){
        cin >> p >> a >> b >> c;
        cout << min({(((p + a - 1) / a) * a) - p, (((p + b - 1) / b) * b) - p, (((p + c - 1) / c) * c) - p}) << endl;
    }
    return 0;
}