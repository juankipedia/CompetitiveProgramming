# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n, k;
lli x[10005];

bool check(lli d){
    lli xi = x[0];
    int ki = 1;
    for(int i = 1; i < n && ki < k; i++)
        if((x[i] - xi) >= d){
            xi = x[i];
            ki++;
        }
    return (ki == k);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i];
    lli lo = 0, hi = 1e17;
    while(lo < hi){
        lli mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    lli xi = x[0], ans = numeric_limits<lli>::max();
    for(int i = 1; i < n; i++)
        if((x[i] - xi) >= lo){
            ans = min(x[i] - xi, ans);
            xi = x[i];
        }
    cout << ans << endl;
    return 0;
}