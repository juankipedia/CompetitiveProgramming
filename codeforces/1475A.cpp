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
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
            bool ok = false;
            while(n % 2 == 0) n /= 2;
            if(n != 1) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
    return 0;
}