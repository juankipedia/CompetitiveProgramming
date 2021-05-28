# include <bits/stdc++.h>
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
        while(n > 0){
            if(n % 11 == 0) break;
            n -= 111;
        }
        if(n < 0) cout << "NO" << endl;
        else cout << "YES" << endl; 
    }
    return 0;
}