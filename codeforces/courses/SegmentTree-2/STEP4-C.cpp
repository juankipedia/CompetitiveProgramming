#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli MAXN = 500003;
const lli SIZE = 3L * MAXN * 2;
int n;
string t;
lli sta[SIZE], st[SIZE], bc[SIZE], X, L;
bool stab[SIZE], rb[SIZE], lb[SIZE];

# define mid (ss + (se - ss) / 2)
# define li (2 * si + 1)
# define ri (2 * si + 2)

void propagate(lli si){
    if(stab[si]){
        stab[si] = false;
        sta[li] = sta[ri] = sta[si];
        stab[li] = stab[ri] = true;
        if(sta[si]){
            bc[li] = lb[li] = rb[li] = false;
            bc[ri] = lb[ri] = rb[ri] = false;
        }
        else{
            lb[li] = rb[li] = true; bc[li] = 0;
            lb[ri] = rb[ri] = true; bc[ri] = 0;
        }
    }
}

void assign_sum(lli si, lli ss, lli se){
    lli L = stab[li] ? sta[li]  * (mid - ss + 1): st[li];
    lli R = stab[ri] ? sta[ri] * (se - mid): st[ri];
    if(L == 0){
        lb[si] = true;
        rb[si] = rb[ri];
        bc[si] = bc[ri];
    }
    else if(R == 0){
        rb[si] = true;
        lb[si] = lb[li];
        bc[si] = bc[li];
    }
    else{
        bc[si] = bc[li] + bc[ri];
        if(rb[li] || lb[ri]) bc[si]++;
        lb[si] = lb[li];
        rb[si] = rb[ri];
    }
    st[si] = L + R;
}

void assign(lli ss, lli se, lli si, lli l, lli r, lli v){
    if(l <= ss && se <= r){
        sta[si] = v;
        if(v) bc[si] = lb[si] = rb[si] = false; 
        else{
            lb[si] = rb[si] = true;
            bc[si] = 0;
        }
        stab[si] = true;
        return;
    }
    if(se < l || ss > r) return;
    propagate(si);
    assign(ss, mid, li, l, r, v);
    assign(mid + 1, se, ri, l, r, v);
    assign_sum(si, ss, se);
    return;
}
 
lli get_sum(){
    if(stab[0]) return sta[0] * (MAXN * 2 + 1);
    else return st[0];
}

lli get_blancks(){
    if(stab[0]) return 0;
    else if(st[0] == 0) return 0;
    else return bc[0] + 1;
}
 
int main(){
    io_boost;
    cin >> n;
    while(n--){
        cin >> t >> X >> L;
        assign(0, MAXN * 2 - 1, 0, X + MAXN - 1, X + MAXN + L - 2, (t == "W") ? 0 : 1);
        cout << get_blancks() << " ";
        cout << get_sum() << endl;
    }
 
    return 0;
}