# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a > b) swap(a, b);
        //cout << a << " " << b << endl;
        if(a == b){
            cout << "0 0" << endl;
        }
        else{
            ulli off = min((b - a) - (b % (b - a)), b % (b - a));
            if(off < a) cout << b - a << " " << off << endl;
            else cout << b - a << " " << a << endl;
        }
    }
    return 0;
}