#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, x;

int main(){
    cin >> t;
    while(t--){
        cin >> x;
        lli ans = 0;
        for(int i = 1; i <= 9; i++){
            string s = "";
            int n = 0;
            bool o = false;
            while(n < 10000){
                s += to_string(i);
                //cout << s << endl;
                n = stoi(s);
                if(n < 10000)
                    ans += s.size();
                if(n == x){
                    o = true;
                    break;
                }
            }
            if(o) break;
        }
        cout << ans << endl;
    }
    return 0;
}