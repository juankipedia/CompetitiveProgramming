# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a[3];

int main(){
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2];
        ulli s = 0;
        for(int i = 0; i < 3; i++) s += a[i];
        if(s % 9){
            cout << "NO" << endl;
            continue;
        }
        ulli aux = s / 9;
        bool ok = true;
        for(int i = 0; i < 3; i++)
            if(a[i] < aux) ok = false;
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}