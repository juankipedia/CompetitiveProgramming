#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[50];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(min(a[i], a[i + 1]) * 2 < max(a[i], a[i + 1])){
                int mini = min(a[i], a[i + 1]), maxi = max(a[i], a[i + 1]);
                while(mini * 2 < maxi){
                    mini *= 2;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}