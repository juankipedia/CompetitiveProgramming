# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;
bool o[1005];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int c = 1;
        for(int i = 1; i <= n; i++) o[i] = false;
        queue<int> ks;
        bool kss[n + 1] = {false};
        ks.push(k);
        o[k] = true;
        kss[k] = true;
        while(!ks.empty()){
            int ki = ks.front();
            ks.pop();
            for(int i = ki - 1; i >= 1; i--){
                if(ki - i >= i) break;
                if(!o[ki - i]) c++;
                o[ki - i] = true;
                if(!kss[ki - 1]){
                    ks.push(ki - i);
                    kss[ki - i] = true;
                }
            }
        }
        cout << n - c << endl;
        for(int i = 1; i <= n; i++) if(!o[i]) cout << i << " ";
        cout << endl;
    }
    return 0;
}