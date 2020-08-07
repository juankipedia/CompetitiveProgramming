#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int t, n, a[50];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int elem = a[0];
        bool f = true;
        for(int i = 1; i < n; i++){
            if(abs(elem - a[i]) >  1){
                f = false;
                break;
            }
            elem = a[i];
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}