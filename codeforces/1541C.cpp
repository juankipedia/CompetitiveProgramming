# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli t, n, a[100005], acc[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(lli i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        vector<lli> edges;
        lli ans = 0;
        for(lli i = 1; i < n; i++){
            lli e = a[i] - a[i - 1]; 
            ans += e;
            ans -= e * (n - i) * i;
        }
        
        cout << ans << endl;
        
    }
    return 0;
}