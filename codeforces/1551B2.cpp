# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
 
const int MAXN = 200005;
int t, n, k, a[MAXN];
 
int main(){
    cin >> t;
    while(t--){
        map<int, vector<int>> m;
        int c[MAXN] = {0};
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i], m[a[i]].push_back(i);
        for(auto &p: m)
            if(p.second.size() >= k){
                for(int i = 1; i <= k; i++) c[p.second[i - 1]] = i;
                for(int i = k; i < p.second.size(); i++) c[p.second[i]] = -1;
            }
        int cnt = 0;
        vector<pair<int, int>> pos;
        for(int i = 0; i < n; i++){
            if(!c[i]){
                pos.push_back({a[i], i}); cnt++;
            }
            if(cnt == k) cnt = 0;
        }
        if(cnt < k) while(cnt) pos.pop_back(), cnt--;
        
        sort(pos.begin(), pos.end());
        for(int i = 0; i < pos.size(); i++)
            c[pos[i].second] = (i % k) + 1;
        for(int i = 0; i < n; i++)
            if(c[i] != -1) cout << c[i] << " "; 
            else cout << 0 << " ";
        cout << endl;
    }
    return 0;
}