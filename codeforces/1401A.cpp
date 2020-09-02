#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k, t, N;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n <= k) cout << (k - n) << endl;
        else if((n - k) % 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}