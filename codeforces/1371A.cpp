#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 2 == 0) cout << n / 2 << endl;
        else cout << (n - 1) / 2 + 1 << endl;
    }
    return 0;
}