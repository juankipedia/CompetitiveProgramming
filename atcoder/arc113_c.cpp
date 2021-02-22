#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s;
int m[26];

int main(){
    cin >> s;
    int n = s.size();
    lli ans = 0;
   
    for(int i = n - 1; i > 0; i--){
        int c = s[i] - 'a';
        if(s[i] == s[i - 1]){
            ans += n - i - 1 - m[c];
            //cout << ans << " ";
            for(int i = 0; i < 26; i++) m[i] = 0;
            m[c] = n - i;
        }
        else m[c]++;
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}