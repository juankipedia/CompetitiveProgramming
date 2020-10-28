#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, t, m, a[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        lli s = 0;
        for(int i = 0; i < n; i++) cin >> a[i], s += a[i];
        if(s == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    
    }
    return 0;
}