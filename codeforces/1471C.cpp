#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;

int main(){
    cin >> t;
    while (t--){
        cin >> n >> m;
        lli c[m];
        int k[n];
        for(int i = 0; i < n; i++) cin >> k[i];
        for(int i = 0; i < m; i++) cin >> c[i];
        sort(k, k + n, greater<int>());
        lli res = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(j < m && k[i] > j) res += c[j++];
            else res += c[k[i] - 1];
        }
        cout << res << endl;
    }
    
    return 0;
}