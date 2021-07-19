# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAXN = 1005;
lli n, m, t[MAXN], z[MAXN], y[MAXN];
 
bool check(lli T){
    lli ans = 0;
    for(int i = 0; i < n; i++) 
        ans += (T / (t[i] * z[i] + y[i])) * z[i] + min((T % (t[i] * z[i] + y[i])) / t[i], z[i]);
    return ans >= m;
}
 
int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)  cin >> t[i] >> z[i] >> y[i];
    lli lo = 0, hi = 1e9;
    while(lo < hi){
        lli mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
    lli ans = 0;
    for(int i = 0; i < n; i++){
        if(ans >= m){
            cout << 0 << " ";
            continue;
        }
        lli ansi = (lo / (t[i] * z[i] + y[i])) * z[i] + min((lo % (t[i] * z[i] + y[i])) / t[i], z[i]);
        if((ans + ansi) > m) cout << m - ans << " ";
        else cout << ansi << " ";
        ans += ansi;
    }
    cout << endl;
    return 0;
}