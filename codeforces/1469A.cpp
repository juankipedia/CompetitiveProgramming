#include <bits/stdc++.h>
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
        int o, c, q = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '(') o = i;
            else if(s[i] == ')') c = i;
            else q++;
        if(o < c){
            if(q % 2) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else{
            bool ok = false;
            for(int i = o; i < s.size(); i++){
                if(s[i] == '?'){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                cout << "NO" << endl;
                continue;
            }
            ok = false;
            for(int i = c; i >= 0; i--){
                if(s[i] == '?'){
                    ok = true;
                    break;
                }
            }
            if(!ok) cout << "NO" << endl;
            else{
                if(q - 2 >= 0 && q % 2 == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
    return 0;
}