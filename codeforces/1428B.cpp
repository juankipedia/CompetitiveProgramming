#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string g;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> g;
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(g[i] == '<') ok = false;
        if(ok){
            cout << n << endl;
            continue;
        }
        ok = true;
        for(int i = n - 1; i > 0; i--)
            if(g[i - 1] == '>') ok = false;
        if(g[n - 1] == '>') ok = false;
        if(ok){
            cout << n << endl;
            continue;
        }
        lli ans = 0;
        for(int i = 1; i < n; i++)
            if(g[i] == '-' || g[i - 1] == '-') ans++;
        if(g[0] == '-' || g[n - 1] == '-') ans++;
        cout << ans << endl;
    }
    return 0;
}