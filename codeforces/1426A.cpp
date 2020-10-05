#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, x;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        if(n == 1 || n == 2){
            cout << 1 << endl;
        }
        else{
            int f = 2, l = 3, u = x + 2;
            while(n > u){
                l = u + 1;
                u = l + x - 1;
                f++;
            }
            cout << f << endl;
        }
    }
    return 0;
}