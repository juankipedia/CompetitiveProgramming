#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q;
 
lli a[100000], st[300000], pos;
 
lli build(int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = build(ss, mid, 2 * si + 1) + build(mid + 1, se, 2 * si + 2);
}
 
int get_kth(int ss, int se, int si, int kth){
    if(ss == se) return ss;
    int mid = ss + (se - ss) / 2;
    if(st[2 * si + 1] > kth){
        return get_kth(ss, mid, 2 * si + 1, kth);
    }
    else if((kth - st[2 * si + 1]) < st[2 * si + 2]){
        return get_kth(mid + 1, se, 2 * si + 2, kth - st[2 * si + 1]);
    }
    return -1;
}
 
lli update(int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return st[si];
    if(ss == se){
        a[i] = v;
        return st[si] = v;
    }
    int mid = ss + (se - ss) / 2;
    return st[si] = update(ss, mid, 2 * si + 1, i, v) + update(mid + 1, se, 2 * si + 2, i, v);
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 0);
    while (m--){
        cin >> q >> pos;
        if(q == 1) update(0, n - 1, 0, pos, a[pos] == 0 ? 1 : 0);
        else cout << get_kth(0, n - 1, 0, pos) << endl;
    }
    
    return 0;
}