#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
bool a[50], b[50];


int main(){
    cin >> t;
    while (t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int i = 0;
        while(!a[i]) i++;
        int ans = 0, cnt = 0;
        //cout << i << endl;
        for(; i < n; i++){
            if(!a[i]) cnt ++;
            else{
                ans += cnt;
                cnt = 0;
            }
        }
        cout << ans << endl; 
    }
    return 0;
}