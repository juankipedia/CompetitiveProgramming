# include <bits/stdc++.h>
using namespace std;


int t, n, a[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a, a + (2 * n));
        for(int i = 0, j = n; i < n; i++, j++)
            cout << a[j] << " " << a[i] << " ";
        cout << endl;
    }
    return 0;
}