#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        int p = n / 2020;
        int k = p * 2020;
        int h = n - k;
        if(h > p) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}