#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200000]; 

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n - 1, c = -1, ans = 0;
        while(true){
            c = -1;
            while(l < r && min(a[l], a[r]) >= c ){
                c = min(a[l], a[r]);
                if(a[l] < a[r]) l++;
                else r--;
            }
            
            if(l == r)
                break;
            else if(a[l] <= a[r]) r = n - 1;
            else{
                l ++; r = n - 1;
            }     
            ans = l;
            
        }
        cout << ans << endl;
    }
    
    return 0;
}