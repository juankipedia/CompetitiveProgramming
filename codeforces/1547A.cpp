# include <bits/stdc++.h>
using namespace std;



int main(){
    int t, a[2], b[2], f[2];
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1];
        cin >> b[0] >> b[1];
        cin >> f[0] >> f[1];
        int ans = abs(a[0] - b[0]) + abs(a[1] - b[1]);
        if(a[0] == b[0] && a[0] == f[0] && (f[1] > a[1] && f[1] < b[1] || f[1] > b[1] && f[1] < a[1])   ) ans += 2;
        else if(a[1] == b[1] && a[1] == f[1] && (f[0] > a[0] && f[0] < b[0] || f[0] > b[0] && f[0] < a[0])) ans += 2;
        cout << ans << endl;
    }
    return 0;
}