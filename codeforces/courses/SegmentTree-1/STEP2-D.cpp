#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli INF = numeric_limits<lli>::max();
 
int n, m, q;
lli a[100000], st[300000], pos, val;
 
lli build(int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = max(build(ss, mid, 2 * si + 1), build(mid + 1, se, 2 * si + 2));
}
 
lli get_at_least_x(int ss, int se, int si, lli x, int l){
    if(st[si] < x) return n;
    if(ss == se) return ss;
    int mid = ss + (se - ss) / 2;
    if(x <= st[2 * si + 1] && l <= mid){
        lli lans = get_at_least_x(ss, mid, 2 * si + 1, x, l);
        if(lans == n) return get_at_least_x(mid + 1, se, 2 * si + 2, x, l);
        else return lans;
    }
    else if(x <= st[2 * si + 2]) return get_at_least_x(mid + 1, se, 2 * si + 2, x, l);
    else return n;
}
 
lli update(int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return st[si];
    if(ss == se){
        a[i] = v;
        return st[si] = v;
    }
    int mid = ss + (se - ss) / 2;
    if(i > mid){
        return st[si]  = max(st[2 * si + 1], update(mid + 1, se, 2 * si + 2, i, v));
    }
    else{
        return st[si] = max(update(ss, mid, 2 * si + 1, i, v), st[2 * si + 2]);
    }
}
 
int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 0);
    while (m--){
        cin >> q;
        if(q == 1){
            cin >> pos >> val;
            update(0, n - 1, 0, pos, val);
        }
        else{
            cin >> val >> pos;
            int ans = get_at_least_x(0, n - 1, 0, val, pos);
            if(ans != n) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    
    return 0;
}