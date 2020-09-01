#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q, l, r, in;
 
lli ae[100001], ao[100001], ste[300000], sto[300000], val;
 
lli build(lli st[], lli a[], int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = build(st, a, ss, mid, 2 * si + 1) + build(st, a, mid + 1, se, 2 * si + 2);
}
 
lli get_sum(lli st[], lli a[], int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return st[si];
    if(qs > se || ss > qe) return 0;
    int mid = ss + (se - ss) / 2;
    return get_sum(st, a, ss, mid, 2 * si + 1, qs, qe) + get_sum(st, a, mid + 1, se, 2 * si + 2, qs, qe);
}
 
lli update(lli st[], lli a[], int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return st[si];
    if(ss == se){
        a[i] = v;
        return st[si] = v;
    }
    int mid = ss + (se - ss) / 2;
    return st[si] = update(st, a, ss, mid, 2 * si + 1, i, v) + update(st, a, mid + 1, se, 2 * si + 2, i, v);
}
 
int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++)
        if(i % 2) cin >> ao[i];
        else cin >> ae[i];
    build(ste, ae, 0, n - 1, 0); build(sto, ao, 0, n - 1, 0);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> q;
        if(q){
            cin >> l >> r;
            l--; r--;
            lli eans = get_sum(ste, ae, 0, n - 1, 0, l, r);
            lli oans = get_sum(sto, ao, 0, n - 1, 0, l, r);
            if(l % 2) cout << oans - eans << endl;
            else cout << eans - oans << endl;
        }
        else{
            cin >> in >> val;
            in--;
            if(in % 2) update(sto, ao, 0, n - 1, 0, in, val);
            else update(ste, ae, 0, n - 1, 0, in, val);
        }
    }
    return 0;
}