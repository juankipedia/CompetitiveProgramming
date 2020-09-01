#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int t, n;
string s;

int main(){
    io_boost;
    cin >>t;
    while(t--){
        cin >> n;
        map<char, int> m;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++) ++m[s[j]];
        }
        bool ok = true;
        for(const auto &p : m){
            //cout << p.second << endl;
            if(p.second % n){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}