# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/



int main(){
    io_boost;
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a < b) swap(a, b);
        int m = a - b - 1;
        if(m <= 0) cout << -1 << endl;
        else{
            int s = 2 + m * 2;

            if(s < c || s < a || s < b) cout << -1 << endl;
            else if((c + m + 1) > s) cout << c - m - 1 << endl;
            else cout << (c + m  + 1) << endl;
        }
    }
    return 0;
}