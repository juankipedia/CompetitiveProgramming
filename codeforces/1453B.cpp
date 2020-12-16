#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[200005];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        lli mans = 0;
        for(int i = 1; i < n; i++)
            mans += abs(a[i] - a[i - 1]);
        lli ans = numeric_limits<lli>::max();
        ans = mans - max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
        for(int i = 1; i < n - 1; i ++)
            ans = min(mans - (abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1])), ans);
        cout << ans << endl;
    }   
    return 0;
}