# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, u[200005], s[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> v(n + 1);
        for(int i = 0; i < n; i++) cin >> u[i];
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++) v[u[i]].push_back(s[i]);
        lli ans[n + 1] = {0};
        for(int i = 1; i <= n; i++){
            sort(v[i].begin(), v[i].end(), greater<int>());
            lli p[n + 1];
            p[0] = 0;
            for(int j = 0; j < v[i].size(); j++) p[j + 1] = p[j] + v[i][j];
            int s = 1, m = v[i].size();
            while(s <= m){
                int pos = (m / s) * s;
                ans[s] += p[pos];
                s++;
            }
        }   
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}