# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
 
int t;
 
int main(){
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int m[26] = {0};
        for(char c : s) m[c - 'a']++;
        int u = 0;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(m[i] >= 2) ans++;
            else if(m[i]) u++;
        }
        ans += u / 2;
        cout << ans << endl;
    }
    return 0;
}