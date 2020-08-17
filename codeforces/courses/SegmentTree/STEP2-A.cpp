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
 
int n, m;
lli a[100000], seg[300000], pre[300000], suf[300000], sum[300000], pos, val;

void mix(const tup &L, const tup &R, tup &result){
    SUM(result) = SUM(L) + SUM(R);
    SEG(result) = max(max(SEG(L), SEG(R)), PRE(R) + SUF(L));
    PRE(result) = max(PRE(L), SUM(L) + PRE(R));
    SUF(result) = max(SUF(R), SUM(R) + SUF(L));
}
 
tup build(int ss, int se, int si){
    if(ss == se){
        seg[si] = a[ss] < 0 ? 0 : a[ss];
        suf[si] = pre[si] = seg[si];
        sum[si] = a[ss];
        return {seg[si], pre[si], suf[si], sum[si]};
    }
    int mid = ss + (se - ss) / 2;
    tup result;
    mix(build(ss, mid, 2 * si + 1), build(mid + 1, se, 2 * si + 2), result);
    return {seg[si] = SEG(result), pre[si] = PRE(result), suf[si] = SUF(result), sum[si] = SUM(result)};
}

tup update(int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return {seg[si], pre[si], suf[si], sum[si]};
    if(ss == se){
        a[i] = v;
        seg[si] = a[ss] < 0 ? 0 : a[ss];
        suf[si] = pre[si] = seg[si];
        sum[si] = a[ss];
        return {seg[si], pre[si], suf[si], sum[si]};
    }
    int mid = ss + (se - ss) / 2;
    tup result;
    mix(update(ss, mid, 2 * si + 1, i, v), update(mid + 1, se, 2 * si + 2, i, v), result);
    return {seg[si] = SEG(result), pre[si] = PRE(result), suf[si] = SUF(result), sum[si] = SUM(result)};
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 0);
    cout << seg[0] << endl;
    while (m--){
        cin >> pos >> val;
        update(0, n - 1, 0, pos, val);
        cout << seg[0] << endl;
    }
    
    return 0;
}