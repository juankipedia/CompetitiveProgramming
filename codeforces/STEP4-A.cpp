#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli INF = numeric_limits<lli>::max();
int L, R, n, m, t;
lli sta[300000], st[300000], V, sts[300000];
bool stab[300000];
 
void assign(int ss, int se, int si, int l, int r, int v){
    if(l <= ss && se <= r){
        sta[si] = v;
        stab[si] = true;
        sts[si] = 0;
        return;
    }
    if(se < l || ss > r) return;
    if(stab[si]){
        sta[2 * si + 1] = sta[2 * si + 2] = sta[si] + sts[si];
        stab[2 * si + 1] = stab[2 * si + 2] = true;
        sts[2 * si + 1] = sts[2 * si + 2] = 0;
        stab[si] = sts[si] = 0;
    }
    int mid = ss + (se - ss) / 2;
    assign(ss, mid, 2 * si + 1, l, r, v);
    assign(mid + 1, se, 2 * si + 2, l, r, v);
    lli L = sts[2 * si + 1] + (stab[2 * si + 1] ? sta[2 * si + 1]  * (mid - ss + 1): st[2 * si + 1]);
    lli R = sts[2 * si + 2] + (stab[2 * si + 2] ? sta[2 * si + 2] * (se - mid): st[2 * si + 2]);
    st[si] = sts[si] + L + R;
    return;
}
 
lli get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r){
        if(stab[si]) return sta[si] * (se - ss + 1) + sts[si];
        else return st[si] + sts[si];
    }
    if(se < l || ss > r) return 0;
    int mid = ss + (se - ss) / 2;
    if(stab[si]) return sta[si] * (abs(min(se, r) - max(ss, l)) + 1) + sts[si];
    lli L = get_sum(ss, mid, 2 * si + 1, l, r);
    lli R = get_sum(mid + 1, se, 2 * si + 2, l, r);
    return sts[si] + L + R;
}
 
void sum(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sts[si] += v;
        return;
    }
    if(l > se || ss > r) return;
    if(stab[si]){
        sta[2 * si + 1] = sta[2 * si + 2] = sta[si] + sts[si];
        stab[2 * si + 1] = stab[2 * si + 2] = true;
        sts[2 * si + 1] = sts[2 * si + 2] = 0;
        stab[si] = sts[si] = 0;
    }
    int mid = ss + (se - ss) / 2;
    sum(ss, mid, 2 * si + 1, l, r, v);
    sum(mid + 1, se, 2 * si + 2, l, r, v);
    return;
}
int main(){
    io_boost;
    cin >> n >> m;
 
    while(m--){
        cin >> t; 
        if(t == 1){    
            cin >> L >> R >> V;
            assign(0, n - 1, 0, L, R - 1, V);
        }
        else if(t == 2){
            cin >> L >> R >> V;
            sum(0, n - 1, 0, L, R - 1, V);
        } 
        else{
            cin >> L >> R;
            cout << get_sum(0, n - 1, 0, L, R - 1) << endl;
        }
    }
 
    return 0;
}