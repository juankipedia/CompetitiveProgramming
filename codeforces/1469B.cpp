#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, r[100], b[100];

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        cin >> r[0];
        for(int i = 1; i < n; i++){
            cin >> r[i];
            r[i] += r[i - 1];
        }
        cin >> m;
        cin >> b[0];
        for(int i = 1; i < m; i++){
            cin >> b[i];
            b[i] += b[i - 1];
        }
        int maxi = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxi = max(maxi, r[i] + b[j]);
        for(int i = 0; i < n; i++) maxi = max(maxi, r[i]);
        for(int i = 0; i < m; i++) maxi = max(maxi, b[i]);
        cout << maxi << endl;
    }
    
    return 0;
}