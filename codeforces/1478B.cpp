#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, q, d;
lli a[10000];
 
bool check(lli n){
    string ns = to_string(n);
    for(int i = 0; i < ns.size(); i++)
        if(ns[i] - '0' == d)
            return true;
    return false;
}
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> q >> d;
        for(int i = 0; i < q; i++) cin >> a[i];
 
        for(int i = 0; i < q; i++){
            lli n = a[i];
            while(n > 0 && !check(n)) n -= d;
            if(n >= 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
 
    }
    
    return 0;
}