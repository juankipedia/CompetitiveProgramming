# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli L, R, E;
int t;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> L >> R;
        E = (R + 2 - 1) / 2;
        lli a = (E + E - 1), b = E; 
        if(a >= L && b >= L) cout << a % b << endl;
        else cout << R % L << endl;
    }
    return 0;
}