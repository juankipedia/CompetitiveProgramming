# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 2050){
            cout << -1 << endl;
            continue;
        } 
        else{
            lli ans = 0;
            string num = to_string(n / 2050);
            for(char c : num) ans += c -'0';
            cout << ans << endl; 
        }
    }
    return 0;
}