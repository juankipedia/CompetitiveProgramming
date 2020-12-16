#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, b[1001], l[1001];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < m; i++) cin >> l[i];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(l[j] == b[i]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}