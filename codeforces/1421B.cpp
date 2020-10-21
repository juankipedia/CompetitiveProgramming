#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string g[200];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> g[i];
        
        vector<pair<int, int>> ans;

        if(g[n - 2][n - 1] == g[n - 1][n - 2]){
            //cout << "afsadff" << endl;
            char a = g[n - 2][n - 1];
            //cout << a << endl;
            if(g[0][1] == a) ans.push_back({1, 2});
            if(g[1][0] == a) ans.push_back({2, 1});
        }
        else{
            if(g[0][1] == g[1][0]){
                char a = g[0][1];
                if(g[n - 2][n - 1] == a) ans.push_back({n - 1, n});
                if(g[n - 1][n - 2] == a) ans.push_back({n, n - 1});
            }
            else{
                if(g[0][1] == '1') ans.push_back({1, 2});
                else ans.push_back({2, 1});
                if(g[n - 2][n - 1] == '0') ans.push_back({n - 1, n});
                else ans.push_back({n, n - 1});
            }
        }

        cout << ans.size() << endl;
        for(auto &p : ans) cout << p.first << " " << p.second << endl;


    }
    return 0;
}