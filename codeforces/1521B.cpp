# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, a[100005];
 
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<tuple<int, int, int, int>> ans;
        for(int i = 0; i < n - 1; i++){
            if(__gcd(a[i], a[i + 1]) == 1) continue;
            int m = min(a[i], a[i + 1]);
            a[i + 1] = m;
            a[i] = m + 1;
            while(i > 0 and (__gcd(a[i - 1], a[i]) > 1 or __gcd(a[i + 1], a[i]) > 1)) a[i]++; 
            ans.push_back({i, i + 1, a[i], a[i + 1]});
        }
        
        cout << ans.size() << endl;
        for(auto & e : ans){
            auto &[i, j, x, y] = e;
            cout << i + 1 << " " << j + 1 << " " << x << " " << y << endl;
        }
    }
    return 0;
}