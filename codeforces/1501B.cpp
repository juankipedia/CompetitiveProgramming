# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
        int l[n] = {0}, r[n] = {0};
        for(int i = 0; i < n; i++){
            if(a[i] != -1){
                r[i]++;
                int e = max(i - a[i], 0);
                l[e]++;
            }
        }

        int o = 0;
        for(int i = 0; i < n; i++){
            
            o += l[i];
            
            if(o) cout << 1 << " ";
            else cout << 0 << " ";

            o -= r[i];
        }
        cout << endl;
    }
    return 0;
}