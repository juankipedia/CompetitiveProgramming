#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main(){
    string s;
    cin >> s;
    char c = s[0];
    bool ok = true;
   for(char e: s)
    if(e != c){
        ok = false;
        break;

    }

    if(ok) cout << "Won" << endl;
    else cout << "Lost" << endl;
    return 0;
}