# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        vector<set<int>> v(k);
        for(int i = 0; i < n; i++) v[i % k].insert(s[i]);
        bool ok = true;
        for(int i = 0; i < k; i++){
            if(v[i].size() > 2){
                ok = false;
                break;
            }
            else if(v[i].size() == 2){
                if(*v[i].begin() != '?' && *v[i].rbegin() != '?'){
                    ok = false;
                    break;
                }
                char c;
                if(*v[i].begin() == '?') c = *v[i].rbegin();
                else c = *v[i].begin();
                v[i].clear();
                v[i].insert(c);
            }
        }
        int o = 0, z = 0, q = 0;
        for(int i = 0; i < k; i++){
            if(*v[i].begin() == '1') o++;
            else if(*v[i].begin() == '0') z++;
            else q++;
        }
        int off = max(o, z) - min(o, z);
        if(q < off || (q - off) % 2) ok = false;
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}