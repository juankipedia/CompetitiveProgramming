#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
 
int main(){
    cin >> t;
    while (t--){
        cin >> n;
        int m[n + 1] = {0};
        for(int i = 0, ai; i < n; i++) cin >> ai, m[ai]++;
        int maxi = 0;
        for(int i = 0; i <= n; i++){
            maxi = max(maxi, m[i]);
        }
        cout << maxi << endl;
    }
    
    return 0;
}
