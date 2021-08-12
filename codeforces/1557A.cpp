# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n;
long double a[300005];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        long double maxi = -1e10, sum = 0, sum2 = 0;
        for(int i = 0; i < n; i++) sum2 += a[i];
        for(int i = 0; i < n - 1; i++)
            sum += a[i],
            sum2 -= a[i],
            maxi = max(sum / (i + 1) + sum2 / (n - i - 1), maxi);
        cout << fixed << setprecision(10) << maxi << endl; 
    }
    return 0;
}