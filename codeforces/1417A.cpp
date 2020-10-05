#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;
lli a[1000];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        lli mini = 1000000; int p;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < mini){
                mini = a[i];
                p = i;
            }
        } 
        lli ans = 0;
        for(int i = 0; i < n; i++){
            if(i != p){
                while((a[i] + mini) <= k){
                    ans++;
                    a[i] += mini;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}