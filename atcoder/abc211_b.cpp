# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


int main(){
    set<string> s, si;
    s.insert("H");
    s.insert("2B");
    s.insert("3B");
    s.insert("HR");
    string ws;
    for(int i = 0; i < 4; i++) cin >> ws, si.insert(ws);
    bool ok = true;
    for(string w: s){
        if(!si.count(w)) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}