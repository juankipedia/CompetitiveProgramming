# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAX = 1e5 + 7;
int t, n, m, a[MAX], b[MAX];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        set<int> bs;
        vector<int> bv;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i], bs.insert(b[i]);
        sort(a, a + n);
        bs.insert(-1);
        for(int e: bs) bv.push_back(e);
        bv.push_back(1e9 + 7);
        int ans = 0;
        for(int i = 1; i < bv.size(); i++){
            int e1 = bv[i - 1], e2 = bv[i];
            int l = upper_bound(a, a + n, e1) - a, r = lower_bound(a, a + n, e2) - a;
            r--;
            if(l > r) continue;
            ans = max(r - l + 1, ans);
        }

        if(!ans) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}