# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 3e5 + 5;
int n;
ulli a[MAXN];
lli c[(1ull << 20ull) + 5][2];

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    lli ans = 0;
    memset(c, 0, sizeof(c));
    ulli acc = 0;
    c[0][1] = 1;
    for(int i = 0; i < n; i++){
        acc = acc ^ a[i];
        ans += c[acc][i % 2];
        c[acc][i % 2]++;
        // cout << ans << endl;
    }
  
    cout << ans << endl;
    return 0;
}