#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, h[200000];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> h[i];
        int mini = h[0], maxi = h[0];
        bool ok = true;
        for(int i = 1; i < n; i++){
            mini = max(mini - (k - 1), h[i]);
            maxi = min(maxi + k - 1, h[i] + k - 1);
            if(mini > maxi){
                ok = false;
                break;
            }
        }   
        if(h[n - 1] > maxi || h[n - 1] < mini) ok = false;
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}