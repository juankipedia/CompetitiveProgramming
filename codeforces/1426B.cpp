#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, a, b, c, d;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool ok = false;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            cin >> c >> d;
            if(b == c) ok = true;
        }
        if(m % 2 == 0 && ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}