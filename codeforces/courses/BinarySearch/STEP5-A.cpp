# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n;
lli l[55], r[55], k;

bool check(lli x){
    lli ans = 0;
    for(int i = 0; i < n; i++){
        if(x <= l[i]) continue;
        ans += min(x - l[i], r[i] - l[i] + 1);
    }
    return ans <= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    lli lo = -2e9, hi = 2e9;
    while(lo < hi){
        lli x = (lo + hi + 1) / 2;
        if(check(x)) lo = x;
        else hi = x - 1;
    }
    cout << lo << endl;
    return 0;
}