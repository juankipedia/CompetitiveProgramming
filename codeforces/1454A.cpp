#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
int t, n;

int main(){
    io_boost
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 2){
            for(int i = n; i > 0; i--){
                if(i == n / 2 + 1) cout << i - 1 << " ";
                else if(i == n / 2 + 1 - 1) cout << n / 2 + 1 << " ";
                else cout << i << " ";
            }
            cout << endl;

        }
        else{
            for(int i = n; i > 0; i--) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}