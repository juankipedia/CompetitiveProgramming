# include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 200000;

int n;
lli b[MAXN],  a[MAXN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    a[0] = b[0];
    lli maxi = 0;
    maxi = max(maxi, b[0]);
    cout << a[0] << " ";
    for(int i = 1; i < n; i++){
        a[i] = b[i] + maxi;
        maxi = max(maxi, a[i]);
        cout << a[i] << " ";
    }
    cout << endl;

    
    return 0;
}