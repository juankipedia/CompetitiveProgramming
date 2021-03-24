# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int cnt[n + 1] = {0};
        vector<int> ans(m);
        vector<vector<int>> v(m, vector<int>());
        for(int i = 0, k; i < m; i++){
            cin >> k;
            v[i].resize(k);
            for(int j = 0; j < k; j++) cin >> v[i][j], v[i][j]--;
            cnt[v[i][0]]++;
            ans[i] = v[i][0];
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m && cnt[i] > (m + 1) / 2; j++)
                if(v[j].size() > 1 && ans[j] == i)
                    cnt[i]--, ans[j] = v[j][1], cnt[v[j][1]]++;
            if(cnt[i] > (m + 1) / 2){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}