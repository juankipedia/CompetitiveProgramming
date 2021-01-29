#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli n, k;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n == k) cout << 1 << endl;
        else if(n < k){
            cout << (k + n - 1) / n << endl;
        }
        else{
            //cout << k << endl;
            //cout << (k + n - 1) / k << endl;
            k = k * ((k + n - 1) / k);
            //cout << k << endl;
            cout << (k + n - 1) / n << endl;
        }
    }
    return 0;
}