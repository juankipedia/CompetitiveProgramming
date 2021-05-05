# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

int main(){
    cin >> t;
    lli n;
    while(t--){
        cin >> n;
        bool ok = false;
        if(n % 4 == 0){
            lli nn = n / 4;
            lli sn = sqrt(nn);
            if(sn * sn == nn) ok = true;
        }
        if(n % 2 == 0){
            lli nn = n / 2;
            lli sn = sqrt(nn);
            if(sn * sn == nn) ok = true;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}