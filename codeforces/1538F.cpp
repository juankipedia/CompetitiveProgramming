# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

int main(){
    cin >> t;
    while(t--){
        int c = 0, l, r;
        cin >> l >> r;
        for(int i = 10; i <= 1e9; i *= 10){
            c += (r / i);
            c -= (l / i);
        }
        cout << (r - l) + c << endl;
    }
    return 0;
}