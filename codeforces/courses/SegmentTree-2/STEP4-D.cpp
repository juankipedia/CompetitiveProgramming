#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, t, l, r;
lli sts[300000], st[300000], a[100000], d;
lli sts2[300000], st2[300000];
bool stb[300000], stb2[300000];

# define mid (ss + (se - ss) / 2)
# define li (2 * si + 1)
# define ri (2 * si + 2)

lli val_to_sum(lli l, lli r){
    l++;r++;
    return (r * (r + 1) / 2) - ((l - 1) * (l) / 2);
}

void build(int ss, int se, int si){
    if(ss == se){st[si] = a[ss]; return;}
    build(ss, mid, li);
    build(mid + 1, se, ri);
    lli L = stb[li] ? sts[li]  * (mid - ss + 1) + st[li]: st[li];
    lli R = stb[ri] ? sts[ri] * (se - mid) + st[ri]: st[ri];
    st[si] = L + R;
    return;
}

void build2(int ss, int se, int si){
    if(ss == se){st2[si] = a[ss] * (ss + 1); return;}
    build2(ss, mid, li);
    build2(mid + 1, se, ri);
    lli L = stb2[li] ? sts2[li] * val_to_sum(ss, mid) + st2[li]: st2[li];
    lli R = stb2[ri] ? sts2[ri] * val_to_sum(mid + 1, se) + st2[ri]: st2[ri];
    st2[si] = L + R;
    return;
}

void set_sum2(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sts2[si] += v;
        stb2[si] = true;
        return;
    }
    if(ss > r || se < l) return;
    if(stb2[si]){
        sts2[li] += sts2[si]; 
        sts2[ri] += sts2[si];
        sts2[si] = stb2[si] = false;
        stb2[li] = stb2[ri] = true;
    }
    set_sum2(ss, mid, li, l, r, v);
    set_sum2(mid + 1, se, ri, l, r, v);
    lli L = stb2[li] ? sts2[li] * val_to_sum(ss, mid) + st2[li]: st2[li];
    lli R = stb2[ri] ? sts2[ri] * val_to_sum(mid + 1, se) + st2[ri]: st2[ri];
    st2[si] = L + R;
}

void set_sum(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sts[si] += v;
        stb[si] = true;
        return;
    }
    if(ss > r || se < l) return;
    if(stb[si]){
        sts[li] += sts[si]; 
        sts[ri] += sts[si];
        sts[si] = stb[si] = false;
        stb[li] = stb[ri] = true;
    }
    set_sum(ss, mid, li, l, r, v);
    set_sum(mid + 1, se, ri, l, r, v);
    lli L = stb[li] ? sts[li]  * (mid - ss + 1) + st[li]: st[li];
    lli R = stb[ri] ? sts[ri] * (se - mid) + st[ri]: st[ri];
    st[si] = L + R;
}

lli get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r) return st[si] + sts[si] * (se - ss + 1);
    if(ss > r || se < l) return 0;
    if(stb[si]){
        sts[li] += sts[si]; 
        sts[ri] += sts[si];
        sts[si] = stb[si] = false;
        stb[li] = stb[ri] = true;
    }
    lli Lv = get_sum(ss, mid, li, l, r), Rv = get_sum(mid + 1, se, ri, l, r);
    lli L = stb[li] ? sts[li]  * (mid - ss + 1) + st[li]: st[li];
    lli R = stb[ri] ? sts[ri] * (se - mid) + st[ri]: st[ri];
    st[si] = L + R;
    return Lv + Rv;
}

lli get_sum2(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r) return st2[si] + sts2[si] * val_to_sum(ss, se);
    if(ss > r || se < l) return 0;
    if(stb2[si]){
        sts2[li] += sts2[si]; 
        sts2[ri] += sts2[si];
        sts2[si] = stb2[si] = false;
        stb2[li] = stb2[ri] = true;
    }
    lli Lv = get_sum2(ss, mid, li, l, r), Rv = get_sum2(mid + 1, se, ri, l, r);
    lli L = stb2[li] ? sts2[li] * val_to_sum(ss, mid) + st2[li]: st2[li];
    lli R = stb2[ri] ? sts2[ri] * val_to_sum(mid + 1, se) + st2[ri]: st2[ri];
    st2[si] = L + R;
    return Lv + Rv;
}

int main(){
    //io_boost;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 0);
    build2(0, n - 1, 0);
    while(m--){
        cin >> t >> l >> r;
        l--; r--;
        if(t == 1){
            cin >> d;
            set_sum(0, n - 1, 0, l, r, d);
            set_sum2(0, n - 1, 0, l, r, d);
        }
        else cout << get_sum2(0, n - 1, 0, l, r) - (l * get_sum(0, n - 1, 0, l, r)) << endl;
    }
    return 0;
}