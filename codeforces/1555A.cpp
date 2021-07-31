# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t;
lli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 6) cout << 15 << endl;
        else cout << (n + 1) / 2 * 5 << endl;
    }
    return 0;
}