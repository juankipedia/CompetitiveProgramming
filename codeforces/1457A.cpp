#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli n, m, r, c;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m >> r >> c;
        cout << max({abs(r - 1) + abs(c - 1), 
                     abs(r - n) + abs(c - 1), 
                     abs(r - n) + abs(c - m), 
                     abs(r - 1) + abs(c - m)}) 
             << endl;
    }
    
    return 0;
}