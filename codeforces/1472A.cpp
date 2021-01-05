#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
lli w, h, n;
 
int main(){
    cin >> t;
    while(t--){
        cin >> w >> h >> n;
        lli exp = 0;
        while(w && h && (w % 2 == 0 || h % 2 == 0)){
            exp++;
            if(w % 2 == 0) w /= 2;
            else h /= 2;
        }
        if((1LL << exp) >= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}