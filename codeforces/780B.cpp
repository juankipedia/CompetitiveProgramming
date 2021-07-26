# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

typedef long double ld;
const int MAXN = 60005;
int n;
ld x[MAXN], v[MAXN];

bool check(ld t){
    ld l = -1e10, r = 1e10;
    for(int i = 0; i < n; i++){
        ld li = x[i] - t * v[i], ri = x[i] + t * v[i];
        l = max(li, l);
        r = min(ri, r);
        if(l > r) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    ld lo = 0, hi = 1e10;
    for(int i = 0; i < 100; i++){
        ld mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(10) << lo << endl;
    return 0;
}