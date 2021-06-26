# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[105];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ans[2] = {500, 500};
        for(int i = 0; i < n; i++) cin >> a[i];
        int l, r;
        for(int i = 0; i < n; i++){
            if(a[i] == 1) l = i;
            if(a[i] == n) r = i;
        }
        if(l > r) swap(l, r);
        cout << min({n - l, r + 1, l + 1 + n - r}) << endl;;
    }
    return 0;
}