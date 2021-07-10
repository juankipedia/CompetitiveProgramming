# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, k, a[105], b[105];

int main(){
    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        int p1 = 0, p2 = 0;
        vector<int> ans;
        while(p1 < n || p2 < m){
            //cout << p1 << " " << p2 << endl;
            if(p1 < n && !a[p1]){
                ans.push_back(a[p1]);
                k++; 
                p1++;
                continue;
            }
            if(p2 < m && !b[p2]){
                ans.push_back(b[p2]);
                k++; 
                p2++;
                continue;
            }
            bool p1b = false, p2b = false;
            if(p1 < n){
                if(a[p1] <= k){
                    ans.push_back(a[p1]);
                    p1++;
                    p1b = true;
                    continue;
                }
            }

            if(p2 < m){
                if(b[p2] <= k){
                    ans.push_back(b[p2]);
                    p2++;
                    p2b = true;
                    continue;
                }
            }
            
            if(!p1b && !p2b) break;
        }

        if(ans.size() != n + m) cout << -1 << endl;
        else{
            for(int p : ans) cout << p << " ";
            cout << endl;
        }
    }
    return 0;
}