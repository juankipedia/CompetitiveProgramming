#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long int lli;

typedef pair<vector<lli>, lli> PAIR;

lli a[100000], sti[300000], n, q, t, x, y;
vector<lli> st[300000];

void merge_segments(vector<lli> &L, vector<lli> &R, vector<lli> &ans, lli &cl, lli &cr, lli &cans){
    cans = cl + cr;
    lli s[41]= {0};
    for(lli m = 1; m <= 40; m++)
        s[m] = s[m - 1] + L[m - 1];
    for(lli h = 0; h < 40; h++)
        cans += R[h] * (s[40] - s[h + 1]);
    for(lli h = 0; h < 40; h++) ans[h] = L[h] + R[h];
}

void build(lli ss, lli se, lli si){
    if(ss == se){
        st[si].resize(40, 0);
        st[si][a[ss]]++;
        sti[si] = 0;
        return;
    }
    lli mid = ss + (se - ss) / 2, li = 2 * si + 1, ri = 2 * si + 2;
    build(ss, mid, li);
    build(mid + 1, se, ri);
    st[si].resize(40, 0);
    merge_segments(st[li], st[ri], st[si], sti[li], sti[ri], sti[si]);
}

PAIR get_inversions(lli ss, lli se, lli si, lli l, lli r){
    if(l <= ss && se <= r) return {st[si], sti[si]};
    if(l > se || ss > r) return {vector<lli>(40, 0), 0};
    lli mid = ss + (se - ss) / 2;
    PAIR L = get_inversions(ss, mid, 2 * si + 1, l, r), R = get_inversions(mid + 1, se, 2 * si + 2, l, r);
    lli cans;
    vector<lli> vans(40, 0);
    merge_segments(L.first, R.first, vans, L.second, R.second, cans);
    return {vans, cans};
}

void update_inversions(lli ss, lli se, lli si, lli i, lli val){
    if(ss == se){
        st[si][a[ss]]--;
        a[ss] = val;
        st[si][a[ss]]++;
        return;
    }
    lli mid = ss + (se - ss) / 2, li = 2 * si + 1, ri = 2 * si + 2;
    if(i <= mid) update_inversions(ss, mid, li, i, val);
    else update_inversions(mid + 1, se, ri, i, val);
    merge_segments(st[li], st[ri], st[si], sti[li], sti[ri], sti[si]);
}

int main(){
    io_boost;
    cin >> n >> q;
    for(lli i = 0; i < n; i++){
        cin >> a[i]; 
        a[i]--;
    }
    build(0, n - 1, 0);
    while(q--){
        cin >> t >> x >> y;
        x--; y--;
        if(t == 1) cout << get_inversions(0, n - 1, 0, x, y).second << endl;
        else update_inversions(0, n - 1, 0, x, y);
    }
    return 0;
}