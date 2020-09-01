#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q, l, r, in;
 
lli a[100001], st[300000], v;
bool stb[300000];
 
void set_val(int ss, int se, int si, int qs, int qe, lli val){
    if(qs <= ss && se <= qe){
        st[si] = val;
        stb[si] = true;
        return;
    }
    if(qs > se || ss > qe) return;
    
    int mid = ss + (se - ss) / 2;

    if(stb[si]){

        st[2 * si + 1] = st[2 * si + 2] = st[si];
        stb[2 * si + 1] = stb[2 * si + 2] = true;
        stb[si] = false;
    }
    set_val(ss, mid, 2 * si + 1, qs, qe, val);
    set_val(mid + 1, se, 2 * si + 2, qs, qe, val);
    return;
}
 
lli get_val(int ss, int se, int si, int i){
    if(ss == se) return st[si];
    int mid = ss + (se - ss) / 2;
    if(stb[si]) return st[si];
    if(i <= mid) return get_val(ss, mid, 2 * si + 1, i);
    else return get_val(mid + 1, se, 2 * si + 2, i);
}
 
 
int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> q;
        if(q == 2){
            cin >> in;
            cout << get_val(0, n - 1, 0, in) << endl;
        }
        else{
            cin >> l >> r >> v;
            set_val(0, n - 1, 0, l, r - 1, v);
        }
    }
    return 0;
}