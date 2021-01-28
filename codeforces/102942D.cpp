#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        int r = a ^ b;
        bool ok = false;
        for(int i = 0; i < a; i++){
            if((i ^ b) > r){
                ok = true;
                break;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
    
    return 0;
}