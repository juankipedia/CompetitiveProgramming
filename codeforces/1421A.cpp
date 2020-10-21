#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a, b, x;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a > b) swap(a, b);
        x = 0;
        for(ulli i = 0; i < 64; i++)
            if(a & (1 << i)) x = x | (1 << i);
        cout << (a ^ x) + (b ^ x) << endl;
    }
    return 0;
}