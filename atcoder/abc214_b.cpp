# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int main(){
    int S, T;
    cin >> S >> T;
    lli ans = 0;
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++)
            for(int k = 0; k <= 100; k++)
                if((i + j + k) <= S && (i * j * k) <= T) ans ++;
    cout << ans << endl;
    return 0;
}