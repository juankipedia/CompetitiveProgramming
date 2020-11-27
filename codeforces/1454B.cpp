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
        map<int, int> f;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ++f[a[i]];
        }
        int val = -1;
        for(auto p: f){
            if(p.second == 1){
                val = p.first;
                break;
            }
        }
        if(val == -1) cout << -1 << endl;
        else{
            for(int i = 0; i < n; i++){
                if(a[i] == val){
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}