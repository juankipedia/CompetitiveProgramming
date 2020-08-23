#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q;
 
lli a[100001], st[300000], l, r, p[100000];
 
lli build(int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = build(ss, mid, 2 * si + 1) + build(mid + 1, se, 2 * si + 2);
}
 
lli get_sum(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return st[si];
    if(qs > se || ss > qe) return 0;
    int mid = ss + (se - ss) / 2;
    return get_sum(ss, mid, 2 * si + 1, qs, qe) + get_sum(mid + 1, se, 2 * si + 2, qs, qe);
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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++){
        cout << get_sum(0, n, 0, p[i], n) << " ";
        update(0, n, 0, p[i], 1);
    }
    cout << endl;    
    return 0;
}