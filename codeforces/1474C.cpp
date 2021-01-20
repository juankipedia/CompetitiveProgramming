#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[2000 + 5];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a, a + (2 * n));
        int X;
        for(int i = 0; i < 2 * n - 1; i++){
            X = a[2 * n - 1] + a[i];
            int cnt[a[2 * n - 1] + 1] = {0};
            for(int j = 0; j < 2 * n - 1; j++)
                if(j != i) cnt[a[j]]++;
            int x = a[2 * n - 1];
            bool ok = true;
            vector<pair<int, int>> ans;
            ans.push_back({a[2 * n - 1], a[i]});
            for(int j = 2 * n - 2; j >= 0; j--){
                if(!cnt[a[j]]) continue;
                cnt[a[j]]--;
                int k = lower_bound(a, a + (2 * n), x - a[j]) - a;
                
                if(k == (2 * n) || k == j ||  a[k] !=  (x - a[j]) || !cnt[a[k]]){
                    ok = false;
                    break;
                }

                cnt[a[k]]--;
                ans.push_back({a[j], a[k]});
                x = a[j];
            }
            if(ok){
                cout << "YES" << endl;
                cout << X << endl;
                for(auto &p: ans) cout << p.first << " " << p.second << endl;
                break;
            }
            X = -1;
        }
        if(X == -1) cout << "NO" << endl;
    }
    return 0;
}