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
 
pair<lli, lli> get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r){
        lli len = se - ss + 1;
        return {st[si] + sta[si] * len, len};
    }
    if(se < l || ss > r) return {0, 0};
    int mid = ss + (se - ss) / 2;
    pair<lli, lli> lr = get_sum(ss, mid, 2 * si + 1, l, r), rr = get_sum(mid + 1, se, 2 * si + 2, l, r);
    return {sta[si] * (lr.second + rr.second) + lr.first + rr.first, lr.second + rr.second };
}
 
void add(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sta[si] += v;
        return;
    }
    if(se < l || ss > r) return;
    int mid = ss + (se - ss) / 2;
    add(ss, mid, 2 * si + 1, l, r, v);
    add(mid + 1, se, 2 * si + 2, l, r, v);
    int li = 2 * si + 1, ri = 2 * si + 2;
    st[si] = st[li] + sta[li] * (mid - ss + 1) + st[ri] + sta[ri] * (se - mid);
}
 
int main(){
    io_boost;
    cin >> n >> m;

    while(m--){
        cin >> t; 
        if(t == 1){    
            cin >> L >> R >> V;
            add(0, n - 1, 0, L, R - 1, V);
        }
        else{
            cin >> L >> R;
            cout << get_sum(0, n - 1, 0, L, R - 1).first << endl;
        }
    }
 
    return 0;
}