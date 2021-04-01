# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s;

int main(){
    cin >> s;
    bool ok = true;
    for(int i = 2; i < s.size(); i++){
        int a = s[i - 1] - 'A', b = s[i - 2] - 'A', c = s[i] - 'A';
        if((a + b) % 26 != c) ok = false;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}