# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, r, b, d;

int main(){
    cin >> t;
    while(t--){
        cin >> r >> b >> d;
        if(r > b) swap(r, b);
        if(b - r <= d) cout << "YES" << endl;
        else{
            if(b % r == 0){
                if((b / r) - 1 <= d) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else{
                if((b / r) <= d) cout << "YES" << endl;
                else cout << "NO" << endl;
            }

        }

    }
    return 0;
}