#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, f[200005], l[200005];
string s, t;

int main(){
    cin >> n >> m;
    cin >> s >> t;
    int j = m - 1;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == t[j]){
            l[j] = i;
            j--;
        }
        if(j < 0) break;
    }
    j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[j]){
            f[j] = i;
            j++;
        }
        if(j >= n) break;
    }
    int ans = 0;
    for(int i = 1; i < m; i++){
        ans = max(ans, l[i] - f[i - 1]);
    }
    cout << ans << endl;
    return 0;
}