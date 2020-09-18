#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, m, l, r;
lli st[300000], sta[300000], v;
bool stb[300000];

lli get_at_least_x(int ss, int se, int si, int l, lli x){
    if((st[si] + sta[si]) < x) return -1;
    if(ss == se) return ss;
    int mid = ss + (se - ss) / 2;
    if(stb[si]){
        int li = 2 * si + 1, ri = 2 * si + 2;
        sta[li] += sta[si];
        sta[ri] += sta[si];
        stb[li] = stb[ri] = true;
        stb[si] = false;
        sta[si] = 0;
        st[si] = max(st[li] + sta[li], st[ri] + sta[ri]);
    }

    int ans = -1;
    if((l <= mid) && (x <= (st[2 * si + 1] + sta[2 * si + 1]))) ans = get_at_least_x(ss, mid, 2 * si + 1, l, x);
    if(ans == -1 && ((l <= se) && (x <= (st[2 * si + 2] + sta[2 * si + 2])))) ans = get_at_least_x(mid + 1, se, 2 * si + 2, l, x);
    return ans;
}

void add(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sta[si] += v;
        stb[si] = true;
        return;
    }
    if(se < l || ss > r) return;
    int mid = ss + (se - ss) / 2;
    add(ss, mid, 2 * si + 1, l, r, v);
    add(mid + 1, se, 2 * si + 2, l, r, v);
    int li = 2 * si + 1, ri = 2 * si + 2;
    st[si] = max(st[li] + sta[li], st[ri] + sta[ri]);
}

int main(){
    io_boost;
    cin >> n >> m;

    while (m--){
        cin >> t;
        if(t == 1){
            cin >> l >> r >> v;
            add(0, n - 1, 0, l, r - 1, v);
        }
        else{
            cin >> v >> l;
            cout << get_at_least_x(0, n - 1, 0, l, v) << endl;
        }
    }
    
    return 0;
}