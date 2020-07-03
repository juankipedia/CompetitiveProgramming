#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long int lli;

int t, n;
lli a[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<lli> v1, v2;
        for(int i = 0; i < n; i += 2){
            if(i + 1 >= n)
                break;
            v1.push_back(a[i + 1] - a[i]);
        }
        for(int i = 1; i < n; i += 2){
            if(i + 1 >= n)
                break;
            v2.push_back(a[i] - a[i + 1]);
        }
        lli s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        for(const lli &e: v1){
            c1 = max(0ll, c1 + e);
            s1 = max(s1, c1);
        }
        for(const lli &e: v2){
            c2 = max(0ll, c2 + e);
            s2 = max(s2, c2);
        }
        lli ans = 0;
        for(int i = 0; i < n; i += 2) ans += a[i];
        cout << ans  + max(s1, s2) << endl;
    }
    return 0;
}