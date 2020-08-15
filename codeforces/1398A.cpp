#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[50000];

int main(){
    cin >> t; 
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(a[0] + a[1] <= a[n - 1]) cout << 1 << " " << 2 << " " << n << endl;
        else cout << -1 << endl;
    }
    return 0;
}