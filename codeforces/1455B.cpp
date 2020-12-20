#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int T, X;
int main(){
    io_boost
    cin >> T;
    while (T--){
        cin >> X;
        int POS = 0; 
        int i = 1;
        while(POS < X){
            POS += i;
            i += 1;
        }
        i -= 1;
        if((POS - X) == 1) cout << i + 1 << endl;
        else cout << i << endl;
    }
    return 0;
}