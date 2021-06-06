# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, s[4];

int main(){
    cin >> t;
    while(t--){
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        int f[] = {max(s[0], s[1]), max(s[2], s[3])};
        sort(s, s + 4);
        sort(f, f + 2);
        if(f[0] == s[2] && f[1] == s[3]) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}