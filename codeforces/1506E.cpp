# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, q[200007];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> q[i];
        set<int> s, s2;
        for(int i = 1; i <= n; i++) s.insert(i), s2.insert(i);
        s.erase(q[0]);
        s2.erase(q[0]);
        vector<int> ans, ans2;
        bool pos[n];
        pos[0] = true;
        for(int i = 1; i < n; i++){
            if(q[i] == q[i - 1]){
                ans.push_back(*s.begin());
                auto it = s2.upper_bound(q[i]);
                it--;
                ans2.push_back(*it);
                s2.erase(*it);
                s.erase(*s.begin());
                pos[i] = false;
            }
            else{
                pos[i] = true;
                s.erase(q[i]);
                s2.erase(q[i]);
            }
        }
        for(int i = 0, j = 0; i < n; i++){
            if(pos[i]) cout << q[i] << " ";
            else{
                cout << ans[j] << " ";
                j++;
            }
        }
        cout << endl;

        for(int i = 0, j = 0; i < n; i++){
            if(pos[i]) cout << q[i] << " ";
            else{
                cout << ans2[j] << " ";
                j++;
            }
        }
        cout << endl;
    }
    return 0;
}