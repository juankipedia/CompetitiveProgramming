#include <iostream>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int n, t, a, b, c, d, l_i, u_i, l, u;

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >>  a >> b >> c >> d;
        l_i = a - b; u_i = a + b;
        l = c - d;
        u = c + d;
        if(l_i * n > u || u_i * n < l) cout << "NO" << endl;
        else cout << "YES" << endl;
        
    }
    return 0;
}