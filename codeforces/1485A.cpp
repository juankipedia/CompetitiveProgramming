#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
lli a, b;
 
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        int ans = 1e9;
        for(int i = 0; i < 31; i++){
            lli B = b + i;
            if(B == 1) continue;
            lli A = a;
            int ansi = i;
            while(A != 0){
                A /= B;
                ansi++;
            }
            ans = min(ans, ansi);
        }
        cout << ans << endl;
    }
    
    return 0;
}