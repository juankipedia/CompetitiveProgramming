#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[300];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0, j = n - 1; i <= j; i++, j--){
            if(i != j) cout << a[i] << " " << a[j] << " ";
            else cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}