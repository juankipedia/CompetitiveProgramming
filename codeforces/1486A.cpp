#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli h[105];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        lli s = 0;
        for(int i = 0; i < n; i++) cin >> h[i], s += h[i];
        bool flag = 1;
        for(int i = 0; i < n - 1; i++){
            if(h[i] < i) flag = 0;
            h[i + 1] += h[i] - i;
            h[i] = i;
        }
        for(int i = 0; i < n - 1; i++){
            if(h[i] >= h[i + 1]){
                flag = 0;
                break;
            }
        }
        if(!flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}