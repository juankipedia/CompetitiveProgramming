# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli n, k, a[100005], b[100005];
bool check(lli x){
    lli ans = 0;
    for(lli i = 0; i < n; i++){ 
        lli X = x - a[i];
        ans += upper_bound(b, b + n, X) - b;
    }
    return ans >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);
    lli lo = 0, hi = 1e11;
    while(lo < hi){
        lli x = (lo + hi) / 2;
        if(!check(x)) lo = x + 1;
        else hi = x;
    }
    cout << lo << endl;
    return 0;
}