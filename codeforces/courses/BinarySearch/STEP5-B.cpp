# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli n, k;
bool check(lli x){
    lli ans = 0;
    for(lli i = 1; i <= n; i++) ans += min(n, x / i);
    return ans >= k;
}

int main(){
    cin >> n >> k;
    lli lo = 0, hi = 1e11;
    while(lo < hi){
        lli x = (lo + hi) / 2;
        if(!check(x)) lo = x + 1;
        else hi = x;
    }
    cout << lo << endl;
    return 0;
}