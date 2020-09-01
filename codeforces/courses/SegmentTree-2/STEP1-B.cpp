#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q, l, r, in;
 
lli a[100001], st[300000], est[300000], v;
 
void set_max(int ss, int se, int si, int qs, int qe, lli val){
    if(qs <= ss && se <= qe){
        st[si] = max(val, st[si]);
        return;
    }
    if(qs > se || ss > qe) return;
    int mid = ss + (se - ss) / 2;
    set_max(ss, mid, 2 * si + 1, qs, qe, val);
    set_max(mid + 1, se, 2 * si + 2, qs, qe, val);
    return;
}

lli get_max(int ss, int se, int si, int i){
    if(i < ss || i > se) return -1;
    if(ss == se) return st[si];
    int mid = ss + (se - ss) / 2;
    return max(st[si], 
            max(get_max(ss, mid, 2 * si + 1, i), 
                get_max(mid + 1, se, 2 * si + 2, i)));
}

 
int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> q;
        if(q == 2){
            cin >> in;
            cout << get_max(0, n - 1, 0, in) << endl;
        }
        else{
            cin >> l >> r >> v;
            set_max(0, n - 1, 0, l, r - 1, v);
        }
    }
    return 0;
}