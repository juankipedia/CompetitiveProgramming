#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, p[1000], t;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        int i, j, k;
        bool f = false;
        for(i = 0; i < n; i++){
            j = i + 1;
            for(k = i + 2; k < n; k++){
                if(p[j] > p[k] && p[j] > p[i]){
                    f = true;
                    break;
                }
                if(p[k] > p[j]) j = k;
            }
            if(f) break;
        }
        if(f) cout << "YES\n" << i + 1 << " " << j + 1 << " " << k + 1 << endl;
        else cout << "NO" << endl;
    }
    return 0;
}