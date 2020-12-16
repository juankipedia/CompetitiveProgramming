#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        string w = "2020";
        if(s.substr(0, 4) == w) cout << "YES" << endl;
        else if(s.substr(n - 4, 4) == w) cout << "YES" << endl;
        else{
            int i = 0;
            for(; i < 4; i++)
                if(s[i] != w[i]) break;
            int j = n - (4 - i), k = i;
            for(; j < n; j++, k++)
                if(s[j] != w[k]) break;
            if(j != n || k != 4) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}