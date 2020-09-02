#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, t, s, a[100];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        bool f = false;
        s = 0;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            s += a[i];
        }

        for(int i = 0; i < n; i ++) if(a[i] > s / 2) f = true;
        if(f) cout << "T\n";
        else if(s % 2 == 0) cout << "HL\n";
        else cout << "T\n";
    }
    return 0;
}