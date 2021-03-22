# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        vector<int> z, o;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1') o.push_back(i);
            else z.push_back(i);
        bool ok = true;
        for(int i = 1; i < z.size(); i++)
            if(z[i - 1] + 1 == z[i]){
                ok = false;
                break;
            }
        if(ok){
            cout << "YES" << endl;
            continue;
        }
        ok = true;
        for(int i = 1; i < o.size(); i++)
            if(o[i - 1] + 1 == o[i]){
                ok = false;
                break;
            }
        if(ok){
            cout << "YES" << endl;
            continue;
        }
        int i = 0;
        bool d[s.size()] = {false};
        if(s[0] == '0') i = 1;
        else if(s[1] == '0'){
            i = 2;
            d[0] = true;
        }
        else{
            cout << "NO" << endl;
            continue;
        }
        bool ones = true;
        ok = true;
        for(int j = i; j < s.size(); j++){
            if(s[j] == '1' && ones){
                if(d[j - 1]) ones = false;
                else d[j] = true;
            }
            else if(s[j] == '0' && !ones){
                if(d[j - 1]){
                    ok = false;
                    break;
                }
                else d[j] = true;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}