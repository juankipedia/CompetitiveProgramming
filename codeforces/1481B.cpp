#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, h[100];
lli k;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> h[i];

        int cnt = 0, pos = -1;
        bool p = false;
        while(true){
            bool f = false;
            for(int i = 0; i < n - 1; i++){
                if(h[i] < h[i + 1]){
                    cnt++;
                    f = true;
                    pos = i;
                    h[i]++;
                    break;
                }
            }
            if(cnt >= k){
                if(!f) p = true;
                break;
            }
            if(!f){
                p = true;
                break;
            }

        }
        if(!p) cout << pos + 1 << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}