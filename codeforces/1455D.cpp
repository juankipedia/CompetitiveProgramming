# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, x, a[505];
const int oo = 1000000;
int memo[505][505][505];

int solve(int i, int x, int l){
    if(i >= n) return 0;
    int ans = oo;
    if(memo[i][x][l] != -1) return memo[i][x][l];
    if(a[i] > x && x >= l) ans = 1 + solve(i + 1, a[i], x);
    if(a[i] >= l) ans = min(ans, solve(i + 1, x, a[i]));
    return memo[i][x][l] = ans;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 500; j++)
                for(int k = 0; k <= 500; k++)
                    memo[i][j][k] = -1;
        int ans = solve(0, x, 0);
        if(ans >= oo) cout << -1 << endl;
        else cout << ans << endl;

    }
    return 0;
}