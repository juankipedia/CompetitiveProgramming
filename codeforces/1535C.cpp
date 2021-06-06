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
        lli ans = 0, n = s.size();
        lli size = 0;
        while(size < n && s[size] == '?') size++;
        if(size == n){
            cout << n * (n + 1) / 2 << endl;
            continue;
        }
        size++;
        lli l = -1, len = 0;
        for(int i = size; i < n; i++){
            if(s[i] == '?'){
                if(l == -1) l = i;
                if(s[i - 1] == '0') s[i] = '1';
                else s[i] = '0';
                size++;
            }
            else{
                if(s[i] == s[i - 1]){
                    ans += size * (size + 1) / 2;
                    ans -= len * (len + 1) / 2;
                    if(l != -1){
                        size = i - l + 1;
                        len = i - l;
                    }
                    else size = 1, len = 0;
                    l = -1;
                }
                else{
                    l = -1;
                    size++;
                }
            }
        }
        ans += size * (size + 1) / 2;
        ans -= len * (len + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}