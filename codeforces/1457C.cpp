#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, p, k, x, y;
string a;
lli memo[100005];

lli solve(int i){
    if(i >= n) return 0;
    if(memo[i] != -1) return memo[i];
    if(a[i] == '1') memo[i] = solve(i + k);
    else memo[i] = x + solve(i + k);
    return memo[i];
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        memset(memo, -1, sizeof(memo));
        cin >> n >> p >> k >> a >> x >> y;
        lli del = 0, ans = numeric_limits<lli>::max();
        for(int i = 0; n - i >= p; i++){
            ans = min(del + solve(i + p - 1), ans);
            del += y;
        }
        cout << ans << endl;
    }
    return 0;
}