#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const ulli ONE = 1;
ulli st[300000], a[100000], y;
int n, q, t, x;

ulli build(int ss, int se, int si){
    if(ss == se) return st[si] = (ONE << a[ss]);
    int mid = ss + (se - ss) / 2;
    ulli L = build(ss, mid, 2 * si + 1), R = build(mid + 1, se, 2 * si + 2);
    return st[si] = (L | R);
}

ulli get(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r) return st[si];
    if(l > se || ss > r) return 0;
    int mid = ss + (se - ss) / 2;
    ulli L = get(ss, mid, 2 * si + 1, l, r), R = get(mid + 1, se, 2 * si + 2, l, r);
    return (L | R);
}

ulli update(int ss, int se, int si, int i, ulli val){
    if(ss == se){
        a[ss] = val;
        return st[si] = (ONE << a[ss]);
    }
    int mid = ss + (se - ss) / 2;
    if(i <= mid) return st[si] = update(ss, mid, 2 * si + 1, i, val) | st[2 * si + 2];
    else return st[si] = st[2 * si + 1] | update(mid + 1, se, 2 * si + 2, i, val);
}

int main(){
    io_boost;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];

    build(0, n - 1, 0);
    while(q--){
        cin >> t >> x >> y;
        x--;
        if(t == 1){
            y--;
            ulli s = get(0, n - 1, 0, x, y);
            int ans = 0;
            for(ulli i = 0; i <= 40; i++)
                if(s & (ONE << i)) ans ++;
            cout << ans << endl;
        }
        else update(0, n - 1, 0, x, y);
    }
    
    return 0;
}