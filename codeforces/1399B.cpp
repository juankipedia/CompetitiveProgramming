#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli MAXAB = 1000000000 + 1;
int t, n;
lli a[50], b[50], mina, minb;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        mina = minb = MAXAB;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) mina = min(a[i], mina), minb = min(b[i], minb);
        lli s = 0;
        for(int i = 0; i < n; i++){
            lli w  = min(a[i] - mina, b[i] - minb);
            s += w; s += a[i] - w - mina; s += b[i] - w - minb;
        }
        cout << s << endl;
    }
    return 0;
}