# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
       cin >> n;
       ulli cur = 1, ans = 0;
       vector<ulli> a; 
        while(ans < n){
            a.push_back(cur);
            ans += cur;
            cur *= 3;
        }
        
        while(!a.empty()){
            int lo = 0, hi = a.size() - 1;
            while(lo < hi){
                int mid = (lo + hi + 1) / 2;
                if((ans - a[mid]) >= n) lo = mid;
                else hi = mid - 1;
            }
            if((ans - a[lo]) < n) break;
            ans -= a[lo];
            a.erase(a.begin() + lo);
        }
        cout << ans << endl;
    }
    return 0;
}