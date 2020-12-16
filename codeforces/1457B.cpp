#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, h[100000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> h[i];
        int ans = numeric_limits<int>::max();
        for(int i = 1; i <= 100; i++){
            int cnt = 0;
            for(int j = 0; j < n;){
                if(h[j] == i) j++;
                else{
                    cnt++;
                    for(int w = 0; w < k; w++) j++;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}