#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 30) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            
            if(n == 40)
                cout << 6 << " " <<  3 << " " <<  10 << " " <<  21 << endl;
            else if(n == 44)
                cout << 6 << " " <<  7 << " " <<  10 << " " <<  21 << endl;
            else if(n == 36)
                cout << 5 << " " <<  6 << " " <<  10 << " " <<  15 << endl;
            else 
                cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;;
        }
    }
    return 0;
}