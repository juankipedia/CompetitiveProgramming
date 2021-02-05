#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;

int t, n, m, a[MAXN], b[MAXN], c[MAXN];
int p[MAXN];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> q[n];
        for(int i = 0; i < n; i++) p[i] = -1;
        for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i]--;
            if(b[i] == a[i]) p[b[i]] = i;
            else q[b[i]].push_back(i);
        }
        int ans[m], s = 0;
        pair<int, int> cp[m];
        for(int i = 0; i < m; i++) cp[i] = {-1, -1};
        for(int i = 0; i < m; i++){
            cin >> c[i];
            c[i]--;
            if(q[c[i]].size()){
                ans[i] = (*q[c[i]].rbegin()) + 1;
                q[c[i]].pop_back();
                p[c[i]] = ans[i] - 1;
                cp[i] = {s, ans[i]};
                s = 0;
            }
            else if(p[c[i]] != -1){
                ans[i] = p[c[i]] + 1;
                cp[i] = {s, ans[i]};
                s = 0;
            }
            else s++;
        }

        for(int i = 0; i < n; i ++){
            if(q[i].size()){
                s = 3;
                break;
            }
        }

        if(s) cout << "NO" << endl;
        else{
            for(int i = m - 1; i >= 0;){
                if(cp[i].first != -1){
                    
                    for(int j = 1; j <= cp[i].first; j++){
                        
                        ans[i - j] = cp[i].second;
                    }
                    i -= cp[i].first;
                }
                i--;
            }
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << ans[i] << " ";
            cout << endl;
        }
    }
    
    return 0;
}