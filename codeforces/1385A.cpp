#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli x, y, z, a, b, c;
int main(){
    cin >> t;
    while(t--){
        cin >> x >> y >> z;
        if(x != y){
            b = x; c = y;
            if(max(b, c) != z) cout << "NO" << endl;
            else cout << "YES\n" << min(b,c) << " " << b << " " << c << endl;
        }
        else{
            a = x;
            if(z > a) cout << "NO" << endl;
            else cout << "YES\n" << a << " " << z << " " << z << endl;

        }
        
    }
    return 0;
}