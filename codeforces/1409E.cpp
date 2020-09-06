#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m[3][200000];
lli k, xi, p[200000];

int f(int l, int i){
    if(i >= n || l == 0) return 0;
    if(m[l][i] != -1) return m[l][i];
    int j = upper_bound(p, p + n, p[i] + k) - p;
    m[l][i] = max(j - i + f(l - 1, j), f(l, i + 1));
    return m[l][i];
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> xi;
        sort(p, p + n);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < n; j++) m[i][j] = -1;
        cout << f(2, 0) << endl;
    }
    return 0;
}