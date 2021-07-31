# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        lli a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        lli ans = numeric_limits<lli>::min();
        for(lli i = 0; i < n; i++)
            for(lli j = i - 1; j >= max(0, n - 300); j--)
                ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
        cout << ans << endl;
    }   
    return 0;
}