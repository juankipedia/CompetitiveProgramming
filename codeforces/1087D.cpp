# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, s, d[100005];
int main(){
    cin >> n >> s;
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    long double l = 0;
    for(int i = 1; i <= n; i++) if(d[i] == 1) l++;
    cout << fixed << setprecision(10) << 2 * s / l << endl;;

    return 0;
}