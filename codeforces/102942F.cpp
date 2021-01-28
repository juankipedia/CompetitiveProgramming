#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5;
int t, n;
lli k;
lli a[MAXN], cost;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        int m[1000005] = {0};
        int l = 0, r = 0;
        cost = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!m[a[r]]) cost += a[r]; 
            m[a[r]]++;
            //cout << cost << endl;
            while(cost > k){
                m[a[l]] --;
                if(!m[a[l]]) cost -= a[l];
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
            
        }
        cout << ans << endl;
    }
    
    return 0;
}