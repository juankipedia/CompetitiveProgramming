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

# define mid (ss + (se - ss) / 2)
# define li (2 * si + 1)
# define ri (2 * si + 2)

void propagate(int si){
    if(stab[si]){
        sta[li] = sta[ri] = sta[si];
        stab[li] = stab[ri] = true;
        sts[li] = sts[ri] = sts[si];
        stab[si] = sts[si] = 0;
    }
    else{
        sts[li] += sts[si]; 
        sts[ri] += sts[si];
        sts[si] = 0;
    }
}

void assing_sum(int si, int ss, int se){
    lli L = (sts[li] * (mid - ss + 1)) + (stab[li] ? sta[li]  * (mid - ss + 1): st[li]);
    lli R = (sts[ri] * (se - mid)) + (stab[ri] ? sta[ri] * (se - mid): st[ri]);
    st[si] = L + R;
}

void assign(int ss, int se, int si, int l, int r, int v){
    if(l <= ss && se <= r){
        sta[si] = v;
        stab[si] = true;
        sts[si] = 0;
        return;
    }
    if(se < l || ss > r) return;
    propagate(si);
    assign(ss, mid, li, l, r, v);
    assign(mid + 1, se, ri, l, r, v);
    assing_sum(si, ss, se);
    return;
}
 
lli get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r){
        lli ans;
        if(stab[si]) return (sta[si] + sts[si]) * (se - ss + 1);
        else return st[si] + sts[si] * (se - ss + 1);
    }
    if(se < l || ss > r) return 0;
    propagate(si);
    lli L = get_sum(ss, mid, li, l, r);
    lli R = get_sum(mid + 1, se, ri, l, r);
    assing_sum(si, ss, se);
    return L + R;
}
 
void sum(int ss, int se, int si, int l, int r, lli v){
    if(l <= ss && se <= r){
        sts[si] += v;
        return;
    }
    if(l > se || ss > r) return;
    propagate(si);
    sum(ss, mid, li, l, r, v); 
    sum(mid + 1, se, ri, l, r, v);
    assing_sum(si, ss, se);
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