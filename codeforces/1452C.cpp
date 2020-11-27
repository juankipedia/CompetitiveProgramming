#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> a, b;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') a.push('(');
            if(s[i] == '[') b.push('[');
            if(s[i] == ']' && b.size() > 0){ans++; b.pop();};
            if(s[i] == ')' && a.size() > 0){ans++; a.pop();};
        }
        cout << ans << endl;
    }
    return 0;
}