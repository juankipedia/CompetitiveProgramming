#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, t, L, R;
lli st[300000], sta[300000], V;


lli get_and(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r) return st[si] | sta[si];
    if(se < l || ss > r) return -1;
    int mid = ss + (se - ss) / 2;
    lli L = get_and(ss, mid, 2 * si + 1, l, r), R = get_and(mid + 1, se, 2 * si + 2, l, r), ans = 0;
    if(L == -1) ans = R;
    else if(R == -1) ans = L;
    else ans = R & L;
    return sta[si] | ans;
}
 
void set_or(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sta[si] = sta[si] | v;
        return;
    }
    if(se < l || ss > r) return;
    int mid = ss + (se - ss) / 2;
    set_or(ss, mid, 2 * si + 1, l, r, v);
    set_or(mid + 1, se, 2 * si + 2, l, r, v);
    int li = 2 * si + 1, ri = 2 * si + 2;
    st[si] = (st[li] | sta[li]) & (st[ri] | sta[ri]);
}
 
int main(){
    io_boost;
    cin >> n >> m;
    while(m--){
        cin >> t; 
        if(t == 1){    
            cin >> L >> R >> V;
            set_or(0, n - 1, 0, L, R - 1, V);
        }
        else{
            cin >> L >> R;
            cout << get_and(0, n - 1, 0, L, R - 1) << endl;
        }
    }
 
    return 0;
}