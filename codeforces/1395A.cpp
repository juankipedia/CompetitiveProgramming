#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli c[4];

int main(){
    cin >> t;
    while (t--){
        cin >> c[0] >> c[1] >> c[2] >> c[3];
        int odd = 0;
        lli n = numeric_limits<lli>::max();
        for(int i = 0; i < 3; i++){
            if(c[i] % 2) odd++;
            n = min(n, c[i]);
        }
        if(c[3] % 2){
            if(odd == 0  || (odd == 2 && n >= 1) || (odd == 3 && n >= 1)) cout << "Yes\n";
            else cout << "No\n";
        }
        else{
            if(odd == 1 || odd == 0 || (odd == 3 && n >= 1)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    
    return 0;
}