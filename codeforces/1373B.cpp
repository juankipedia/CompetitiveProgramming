#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string s, si;
int main(){
    cin >> t;
    while(t--){
        cin >> s;
        bool at = true;

        while(s.size() > 1){
            bool p = false;
            si = "";
            si += s[0];
            
            for(int i = 1; i < s.size(); i++){
                if(s[i] != s[i - 1] && !p){
                    p = true;
                    si.pop_back();
                }
                else si += s[i];
            }

            s = si;
            if(!p) break;
            at = !at;
        }
        if(at) cout << "NET" << endl;
        else cout << "DA" << endl;
    }
    return 0;
}