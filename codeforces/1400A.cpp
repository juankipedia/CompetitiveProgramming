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
    cin >> t;
    while(t--){
        cin >> n >> s;
        string ans = "";
        for(int i = 0, j = 0; (i + j) < (2 * n - 1); i++, j++) ans += s[i + j];
        cout << ans << endl;
    }
    
    return 0;
}