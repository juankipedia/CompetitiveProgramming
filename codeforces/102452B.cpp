#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0, u; i < n - 1; i++) cin >> u >> u; 
        if(n % 2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}