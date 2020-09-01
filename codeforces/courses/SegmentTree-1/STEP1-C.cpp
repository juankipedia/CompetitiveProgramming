#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli INF = numeric_limits<lli>::max();
 
int n, m, q;
lli a[100000], st[300000], stn[300000], l, r;
 
pair<lli, int> build(int ss, int se, int si){
    if(ss == se){
        stn[si] = 1;
        st[si] = a[ss];
        return {st[si], stn[si]};
    };
    int mid = ss + (se - ss) / 2;

    auto L = build(ss, mid, 2 * si + 1), R = build(mid + 1, se, 2 * si + 2);
    if(L.first < R.first){
        st[si] = L.first;
        stn[si] = L.second;
    }
    else if(L.first > R.first){
        st[si] = R.first;
        stn[si] = R.second;
    }
    else{
        st[si] = L.first;
        stn[si] = L.second + R.second;
    }
    return {st[si], stn[si]};
}
 
pair<lli, int> get_min(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe){
        return {st[si], stn[si]};
    }
    if(qs > se || ss > qe) return {INF, 0};
    int mid = ss + (se - ss) / 2;
    auto L = get_min(ss, mid, 2 * si + 1, qs, qe), R = get_min(mid + 1, se, 2 * si + 2, qs, qe);
       
    if(L.first < R.first) return {L.first, L.second};
    else if(L.first > R.first) return {R.first, R.second};
    else return {L.first, L.second + R.second};
}
 
pair<lli, int> update(int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return {st[si], stn[si]};
    if(ss == se){
        a[i] = v;
        st[si] = v;
        return {st[si], stn[si]};
    }
    int mid = ss + (se - ss) / 2;
    auto L = update(ss, mid, 2 * si + 1, i, v), R = update(mid + 1, se, 2 * si + 2, i, v);
    if(L.first < R.first){
        st[si] = L.first;
        stn[si] = L.second;
    }
    else if(L.first > R.first){
        st[si] = R.first;
        stn[si] = R.second;
    }
    else{
        st[si] = L.first;
        stn[si] = L.second + R.second;
    }
    return {st[si], stn[si]};
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 0);
    while (m--){
        cin >> q >> l >> r;
        if(q == 1) update(0, n - 1, 0, l, r);
        else{
            auto p = get_min(0, n - 1, 0, l, r - 1);
            cout << p.first << " " << p.second << endl;
        }
    }
    
    return 0;
}