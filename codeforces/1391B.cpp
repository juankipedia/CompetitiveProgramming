#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;
string g[100];
int main(){
    cin >> t;
    while (t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> g[i];
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
            if(g[i][m - 1] == 'R') ans++;
        for(int i = 0; i < m - 1; i++)
            if(g[n - 1][i] == 'D') ans++;

        cout << ans << endl;
    }
    
    return 0;
}