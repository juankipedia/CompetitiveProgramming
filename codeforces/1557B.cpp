# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli a[100005];
int t, n, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        set<lli> s;
        for(int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
        int ki = 0;
        lli l = a[0];
        for(int i = 1; i < n; i++){
            auto it = s.upper_bound(l);
            if(it == s.end() || *it != a[i]) l = a[i], ki++;
            else l = a[i];
        }
        ki++;
        if(ki <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}