# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int t;
ulli n, m;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(m < n){ cout << 0 << endl; continue; }
        m++;
        ulli ans = 0;
        for(lli i = 63; i >= 0; i--){
            bool mi = (1ULL << i) & m, ni = (1ULL << i) & n;
            if(mi && !ni) ans |= (1ULL << i);
            else if(!mi && ni) break; 
        }
        cout << ans << endl;
    }
    return 0;
}