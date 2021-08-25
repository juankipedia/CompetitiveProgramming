# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n, a[1000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        bool sorted = true;
        for(int l = 0; l < n - 1; l++) if(a[l] > a[l + 1]){ sorted = false; break; }
        if(sorted){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            int j = 0;
            if(i % 2) j = 1;
            for(; j < n - 1; j += 2) if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            bool sorted = true;
            ans++;
            for(int l = 0; l < n - 1; l++) if(a[l] > a[l + 1]){ sorted = false; break; }
            if(sorted) break;
        }
        cout  << ans << endl;
    }
    return 0;
}