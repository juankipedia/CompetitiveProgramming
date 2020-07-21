#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, l, r, a, b, c;
lli n, m, k;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> l >> r >> m;
        for(a = l; a <= r; a++){
            n = (m + r - l) / a;
            //if(a == 25)
            //cout << (n * a) << " " << (m - r + l) << " " << (m + r - l) << endl;
            if((n * a) >= (m - r + l) && (n * a) <= (m + r - l)){
                k = m - n * a;
                b = k + l; c = l;
                if(b >= l && b <= r && c >= l && c <= r)
                    break;
                b = k + r; c = r;
                break;
            }
        }
        cout << a  << " " << b << " " << c << endl;
    }
    return 0;
}