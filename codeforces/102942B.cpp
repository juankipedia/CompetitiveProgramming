#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int o = 0, e = 0;
        for(int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] % 2) o++;
            else e++;
            
        }
        if(o == 0){
            cout << -1 << endl;
            continue;
        }
        if(e == 0){
            cout << 0 << endl;
            continue;
        }
        cout << e << endl;
    }
    return 0;
}