#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef tuple<lli, lli, lli, lli> tup;
# define SUM(t) get<3>(t)
# define SUF(t) get<2>(t)
# define PRE(t) get<1>(t)
# define SEG(t) get<0>(t)
 
int n, m, L, R;
lli val;
tup st[300000];
bool stb[300000];

void mix(const tup &L, const tup &R, tup &result){
    SUM(result) = SUM(L) + SUM(R);
    SEG(result) = max(max(SEG(L), SEG(R)), PRE(R) + SUF(L));
    PRE(result) = max(PRE(L), SUM(L) + PRE(R));
    SUF(result) = max(SUF(R), SUM(R) + SUF(L));
}

void apply_val(tup &result, lli val, int len){
    if(val < 0) SEG(result) = SUF(result) = PRE(result) = 0;
    else SEG(result) = SUF(result) = PRE(result) = val * len;
    SUM(result) = val * len;
}

void set_val(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        apply_val(st[si], v, se - ss + 1);
        stb[si] = true;
        return;
    }
    if(ss > r || se < l) return;
    int mid = ss + (se - ss) / 2;
    if(stb[si]){
        stb[si] = false;
        stb[2 * si + 1] = stb[2 * si + 2] = true;
        apply_val(st[2 * si + 1], SUM(st[si]) / (se - ss + 1), mid - ss + 1);
        apply_val(st[2 * si + 2], SUM(st[si]) / (se - ss + 1), se - mid); 
    }
   
    set_val(ss, mid, 2 * si + 1, l, r, v);
    set_val(mid + 1, se, 2 * si + 2, l, r, v);
    mix(st[2 * si + 1], st[2 * si + 2], st[si]);
    return;
}
 
int main(){
    cin >> n >> m;
    while (m--){
        cin >> L >> R >> val;
        set_val(0, n - 1, 0, L, R - 1, val);
        cout << SEG(st[0]) << endl;
    }
    
    return 0;
}