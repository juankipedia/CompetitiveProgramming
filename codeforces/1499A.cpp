# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k1, k2, w, b, t;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k1 >> k2 >> w >> b;
        if(k1 < k2) swap(k1, k2);
        w -= k2;
        k1 -= k2;
        if(k1 / 2 < w) cout << "NO" << endl;
        else{
            b -= k1 / 2;
            if((n - k2 - k1) < b) cout << "NO" << endl;
            else cout << "YES" << endl;
        }

    }
    return 0;
}