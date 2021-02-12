#include <iostream>
using namespace std;

int main(){
    int n, q, k;
    cin >> n >> q >> k;
    int a[n + 7], s[n + 7];
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0; a[n + 1] = k + 1; s[0] = 0;
    for(int i = 1; i <= n; i++)
        s[i] = a[i] - a[i - 1] + a[i + 1] - a[i] - 2 + s[i - 1];
    
    for(int i = 0, l, r; i < q; i++){
        cin >> l >> r;
        if(l == r) cout << k - 1 << endl;
        else cout << s[r - 1] - s[l] + a[l] - 1 + a[l + 1] - a[l] - 1 + a[r] - a[r - 1] - 1 + k - a[r] << endl;
    }
    return 0;
}