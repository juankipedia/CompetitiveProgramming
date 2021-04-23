# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, a[105];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1 && k; i++){
            int ki = k, ai = a[i];
            k -= min(ai, ki);
            a[i] -= min(ai, ki);
            a[n - 1] += min(ai, ki);
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
