# include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
const ulli ONE = 1;
int t, n, f;
lli a[100000], maxi, maxd;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a[0];
        maxi = a[0]; maxd = 0;
        for(int i = 1; i < n; i ++){
            cin >> a[i];
            if(maxi > a[i]){
                maxd = max(maxi - a[i], maxd);
            }
            maxi = max(maxi, a[i]);
        }
        if(maxd == 0) cout << 0 << endl;
        else cout << static_cast<lli>(log2(maxd)) + 1 << endl;
    }
    return 0;
}