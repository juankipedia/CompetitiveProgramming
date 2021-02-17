#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;
lli ai, maxis[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        lli sum = 0, maxi = numeric_limits<lli>::min();
        
        for(int i = 0; i < n; i++){
            cin >> ai;
            sum += ai;
            maxi = max(sum, maxi);
            maxis[i] = maxi;
        }

        while(m--){
            lli x;
            cin >> x;
            if(sum <= 0 && x > maxi){
                cout << -1 << " ";
                continue;
            }
            lli ans = 0;
            if(x > maxi){
                lli d = x - maxi;
                lli r = (d + sum - 1) / sum;
                x -= sum * r;
                ans = r * n;
            }
            int pos = lower_bound(maxis, maxis + n, x) - maxis;
            cout << ans + pos << " ";
        }
        cout << endl;

    }
    
    return 0;
}