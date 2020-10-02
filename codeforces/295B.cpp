#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, d, x[500];
ulli a[500][500], g[500][500];

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j], g[i][j] = a[i][j];

    for(int i = n - 1; i >= 0; i--) cin >> x[i], x[i]--;
    bool sk[n] = {false};
    vector<ulli> ans;
    for(int ki = 0; ki < n; ki++){
        sk[x[ki]] = true;
        int k = x[ki];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        ulli s = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(sk[i] && sk[j])
                    s += g[i][j];
        ans.push_back(s);
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;
    return 0;
}