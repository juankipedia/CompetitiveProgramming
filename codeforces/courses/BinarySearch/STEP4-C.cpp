# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef long double ld;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 100005;
int n, k;
pair<ld, ld> ab[MAXN];
ld x, v[MAXN];

bool check(){
    for(int i = 0; i < n; i++) v[i] = ab[i].first - x * ab[i].second;
    sort(v, v + n, greater<ld>());
    ld s = 0;
    for(int i = 0; i < k; i++) s += v[i];
    return s >= 1e-18;
}

int main(){
    io_boost;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
    ld lo = 0, hi = 1e8;
    for(int i = 0; i < 60; i++){
        x = (lo + hi) / 2;
        if(check()) lo = x;
        else hi = x;
    }
    cout << fixed << setprecision(10) << lo << endl;
    return 0;
}