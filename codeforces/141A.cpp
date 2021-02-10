#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
string s, t, v;
int m[26];
int main(){
    cin >> s >> t >> v;
    for(char c: v) m[c - 'A']++;
    bool ok = true;
    for(char c: s) m[c - 'A']--;
    for(char c: t) m[c - 'A']--;
    for(int i = 0; i < 26; i++){
        if(m[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}