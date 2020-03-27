# include <bits/stdc++.h>

using namespace std;
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int INF = std::numeric_limits<int>::max();
typedef unsigned long long int ulli;

int t;
ulli n, g, b, d, m;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> g >> b;
        ulli h = (n + 1) / 2;
        d  = h/g;
        m = h % g;
        if(m) cout << max(n, d * (g + b) + m) << "\n"; 
        else cout << max(n, g * d + (d - 1) * b) << "\n";
    }    
    return 0;
}