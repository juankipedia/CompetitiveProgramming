#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<lli>::max();

int t;
lli n;

int main(){
    cin >> t;
    while(t--){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
    }
    else{
        lli maxi = 1, sum = 1, cnt = 0, ansi = oo;
        while(sum < n){
            maxi++;
            cnt++;
            lli aux = n - maxi;
            if((cnt + (aux + maxi - 1) / maxi) > ansi) break;
            else ansi = (cnt + (aux + maxi - 1) / maxi);

        }
        cout << ansi << endl;
    }
    }

    return 0;
}