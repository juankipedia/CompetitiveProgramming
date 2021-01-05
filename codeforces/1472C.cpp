#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
lli a[200000], m[200000];
 
lli dp(int i){
    if(i >= n) return 0;
    if(m[i] != -1) return m[i];
    return m[i] = a[i] + dp(a[i] + i);
}
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        memset(m, -1, sizeof(m));
        lli maxi = -1;
        for(int i = 0; i < n; i++) maxi = max(dp(i), maxi);
        cout << maxi << endl;
    }
    
    return 0;
}