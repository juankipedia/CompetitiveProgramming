# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli T;

int main(){
    cin >> T;
    while(T--){
        lli n;
        cin >> n;
        bool f = true;
        lli ans = 0;
        while(n != 0){
            if((n % 4 == 0 && n > 8) || n % 2){
                if(f) ans++;
                n--;
                f = !f;
            }
            else{
                if(f) ans += n / 2;
                n /= 2;
                f = !f;
            }
        }
        cout << ans << endl;
    }
    return 0;
}