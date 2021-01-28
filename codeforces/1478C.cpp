#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli d[200000], df[200000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 2 * n; i++) cin >> d[i];
        sort(d, d + 2 * n);
        bool ok = true;
        for(int i = 1, j = 0; i < 2 * n; i += 2, j++){
            if(d[i] != d[i - 1] || d[i] % 2){
                ok = false;
                break;
            }
            df[j] = d[i - 1];
        }
        if(ok){
            set<lli> a;
            lli f = 0;
            for(int i = n - 1; i >= 0; i--){
                int j = i + 1;
                if((df[i] - 2 * f) <= 0 || (df[i] - 2 * f) % (2 * j) || a.count((df[i] - 2 * f) / (2 * j))){
                    ok = false;
                    break;
                }
                a.insert((df[i] - 2 * f) / (2 * j));
                f += (df[i] - 2 * f) / (2 * j);
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}