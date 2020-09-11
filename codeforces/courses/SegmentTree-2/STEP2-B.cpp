#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli mod = 1e9 + 7;
 
int n, m, t, L, R;
lli st[300000], sta[300000], V;

lli init(int ss, int se, int si){
    if(ss == se) return sta[si] = st[si] = 1;
    int mid = ss + (se - ss) / 2;
    st[si] = init(ss, mid, 2 * si + 1) + init(mid + 1, se, 2 * si + 2);
    sta[si] = 1;
    return st[si];
}
 
lli get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r) return (st[si] % mod * sta[si] % mod) % mod;
    if(se < l || ss > r) return 0;
    int mid = ss + (se - ss) / 2;
    return (sta[si] % mod * (get_sum(ss, mid, 2 * si + 1, l, r) % mod + get_sum(mid + 1, se, 2 * si + 2, l, r) % mod) % mod) % mod;
}
 
void multiply(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sta[si] = (sta[si] % mod * v % mod) % mod;
        return;
    }
    if(se < l || ss > r) return;
    int mid = ss + (se - ss) / 2;
    multiply(ss, mid, 2 * si + 1, l, r, v);
    multiply(mid + 1, se, 2 * si + 2, l, r, v);
    int li = 2 * si + 1, ri = 2 * si + 2;
    st[si] = ((st[li] % mod * sta[li] % mod) % mod + (st[ri] % mod * sta[ri] % mod) % mod) % mod;
}
 
int main(){
    io_boost;
    cin >> n >> m;
    init(0, n - 1, 0);
    while(m--){
        cin >> t; 
        if(t == 1){    
            cin >> L >> R >> V;
            multiply(0, n - 1, 0, L, R - 1, V);
        }
        else{
            cin >> L >> R;
            cout << get_sum(0, n - 1, 0, L, R - 1) << endl;
        }
    }
 
    return 0;
}