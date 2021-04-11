# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s, t, p;
int q;

int main(){
    cin >> q;
    while(q--){
        map<char, int> m;
        cin >> s >> t >> p;
        for(char c: p) m[c]++;
        int i = 0, j = 0, n = s.size(), k = t.size();
        bool ok = true;
        while(j < k){
            if(i < n && s[i] == t[j]){
                i++;
                j++;
            }
            else if(m.count(t[j]) && m[t[j]]){
                m[t[j]]--;
                j++;
            }
            else{
                ok = false;
                break;
            }
        }
        if(!ok || i < n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}