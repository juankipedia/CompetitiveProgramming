#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int INF = 1000000;
int t, ti, n, m[200000][2][3], mt[200000][2][3];
bool a[200000];
int G(int i, bool f, int kills){
    if(i >= n) return 0;
    if(mt[i][f][kills] == ti) return m[i][f][kills];
    mt[i][f][kills] = ti;
    lli ans = INF;
    if(f){
        if(kills == 2) ans = G(i + 1, false, 1);
        else ans = min(
                (a[i] ? 1 : 0) + G(i + 1, true, 2),
                G(i + 1, false, 1)
            );
    }
    else{
        if(kills == 2) ans = (a[i] ? 1 : 0) + G(i + 1, true, 1);
        else ans = min(
                G(i + 1, false, 2),
                (a[i] ? 1 : 0) + G(i + 1, true, 1)
            );
    }
    m[i][f][kills] = ans;
    return ans;
}

int main(){
    io_boost;
    cin >> t;
    for(ti = 1; ti <= t; ti++) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = G(1, true, 1);
        if(a[0]) ans++;
        cout << ans << endl;
    }
    
    return 0;
}