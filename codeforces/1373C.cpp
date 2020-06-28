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
    io_boost;

    cin >> t;
    while(t--){
        cin >> s;
        lli i = 0, j = 0;
        lli v[s.size()];
        for(lli k = 0; k < s.size(); k++){
            if(s[k] == '-') j--;
            else j++;
            v[k] = i;
            if(j < 0 && abs(j) > i) i++;
        }
    
        lli res = 0;
        for(lli k = 0; k < s.size(); k++){
            res += i - v[k] + 1;
        }
        cout << res << endl;
    }
    return 0;
}