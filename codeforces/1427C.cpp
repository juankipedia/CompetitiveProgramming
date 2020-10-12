#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int r, n, t[100001], x[100001], y[100001], memo[100001], best[100002];
 
int main(){
    io_boost;
    cin >> r >> n;
    t[0] = 0; y[0] = x[0] = 1;
    n++;
    for(int i = 1; i < n; i++) cin >> t[i] >> x[i] >> y[i];
    for(int i = n - 1; i >= 0; i--){
        int maxi = 0;
        for(int j = i + 1; j < n && j < (i + 2 * r); j++){
            if((abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[i]) <= t[j])
                maxi = max(memo[j] + 1, maxi);
        }
        memo[i] = maxi;
        best[i] = max(best[i + 1], memo[i]);
        if((i + 2 * r) < n) memo[i] = max(memo[i], best[(i + 2 * r)] + 1);
    }
    cout << memo[0] << endl;
    return 0;
}