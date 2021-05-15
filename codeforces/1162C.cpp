# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k, x[100005];
bool g[100005][3];

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> x[i];
    memset(g, true, sizeof(g));
    g[1][0] = false;
    g[n][1] = false;
    for(int i = 0; i < k; i++){
        g[x[i]][2] = false;
        if(!g[x[i] + 1][2]) g[x[i] + 1][0] = false;
        if(!g[x[i] - 1][2]) g[x[i] - 1][1] = false;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(g[i][0]) ans++;
        if(g[i][1]) ans++;
        if(g[i][2]) ans++;
    }
    cout << ans << endl;
    return 0;
}