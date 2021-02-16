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
        k--;
        if(n % 2){
            lli off = k / n;
            lli pos = k - (off * n);
            if(off == 0 && pos >= n / 2) off++;
            lli a = (pos + (k / (n / 2))) % n;
            lli b = (n - 1) - (k % n);
            if(a == b) a++;

            cout << a + 1 << endl;
        }
        else cout << (k % n) + 1 << endl;
    }
    return 0;
}