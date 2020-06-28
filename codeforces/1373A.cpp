#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli a, b,c;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        lli aa = -1, ba = -1;
        if(a < c)
            aa = 1;
        if(c < (b * a))
            ba = b;

        cout << aa << " " <<  ba << endl;
    }
    
    return 0;
}