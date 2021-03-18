# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;
lli a[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> v(m, 0);
        for(int i = 0; i < n; i++) cin >> a[i], v[a[i] % m]++;
        int l = 1, r = m - 1, ans = 0;
        while(l <= r){
            if(l == r && v[r]) ans++;
            else if(!v[l]) ans += v[r];
            else if(!v[r]) ans += v[l];
            else{
                if(v[l] == v[r]) ans++;
                else{
                    ans++;
                    ans += max(v[l], v[r]) - min(v[l], v[r]) - 1;
                }
            }
            l++; r--;
        }
        if(v[0]) ans++;
        cout << ans << endl;
    }
    
    return 0;
}