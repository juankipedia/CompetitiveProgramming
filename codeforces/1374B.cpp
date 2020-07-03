#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

typedef long long int lli;

lli n, t;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = true; 
        lli cnt = 0;
        while(true){
            if(n == 1) break;
            if(n % 6){
                n *= 2;
                cnt ++;
            }
            if(n % 6 == 0)
                n /= 6;
            else{
                flag = false;
                break;
            }
            cnt++;
        }
        if(flag) cout << cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}