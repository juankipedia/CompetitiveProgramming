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
    cin >> t;
    while(t--){
        cin >> s;
        stack<char> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A') ans.push(s[i]);
            else if(ans.empty()) ans.push(s[i]);
            else ans.pop();
        }
        cout << ans.size() << endl;
    }
    return 0;
}