# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, x, w[105];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> w[i];
        int total = 0;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(total + w[i] == x){
                if(i == n - 1){
                    f = false;
                    break;
                }
                else swap(w[i], w[i + 1]);
            }
            total += w[i];
        }
        if(f){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) cout << w[i] << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}