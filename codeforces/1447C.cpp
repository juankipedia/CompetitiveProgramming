#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
ulli W, wi;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> W;
        vector<pair<ulli, int>> p;
        for(int i = 0; i < n; i++)
            cin >> wi, p.push_back({wi, i + 1});
        sort(p.begin(), p.end());
        vector<int> ans;
        ulli s = 0, l = (W + 2 - 1) / 2;
        int j = 0, i = 0;
        bool f = false;
        while(j < n){
            s += p[j].first;
            ans.push_back(p[j].second);
            while(s > W && i <= j){
                s -= p[i].first;
                ans.erase(ans.begin());
                i++;
            }

            if(s >= l && s <= W){
                f = true;
                break;
            }
            j++;
        }
        if(f){
            cout << ans.size() << endl;
            for(int pos: ans) cout << pos << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}