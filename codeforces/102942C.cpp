#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, a[200000];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int i = 0, j = n - 1, ans = 0;
        bool taken[n] = {false};
        for(int l = 0; l < n; l++) if(a[l] >= k) ans++, taken[l] = true;
        while(i < j){
            if(taken[i]){
                i++;
                continue;
            }
            if(taken[j]){
                j--;
                continue;
            }
            if(a[j] + a[i] >= k){
                ans++;
                j--;
                i++;
            }
            else{
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}