#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

typedef tuple<lli, lli, lli> tup;
# define mid (ss + (se - ss) / 2)
# define li (2 * si + 1)
# define ri (2 * si + 2)
# define A(t) get<0>(t)
# define B(t) get<1>(t)
# define C(t) get<2>(t)

int n, m, t, l, r, in; 
lli sta[600000], stb[600000], stc[600000], a, d; 

void set_progression(int ss, int se, int si, int l, int r, lli a, lli d){
    if(l <= ss && se <= r){
        sta[si] += a;
        stb[si] += d;
        stc[si] += d * l;
        return;
    }
    if(se < l || ss > r) return;
    set_progression(ss, mid, li, l, r, a, d);
    set_progression(mid + 1, se, ri, l, r, a, d);
    return;
}

tup get(int ss, int se, int si, int i){
    if(i < ss || i > se) return {0, 0, 0};
    if(ss == se) return {sta[si], stb[si], stc[si]};
    tup L = get(ss, mid, li, i), R = get(mid + 1, se, ri, i);
    return{
        sta[si] + A(L) + A(R),
        stb[si] + B(L) + B(R),
        stc[si] + C(L) + C(R)
    };
}
 
int main(){
    io_boost;
    cin >> n >> m;
    while (m--){
        cin >> t;
        if(t == 1){
            cin >> l >> r >> a >> d;
            set_progression(1, n, 0, l, r, a, d);
        }
        else{
            cin >> in;
            tup ans = get(1, n, 0, in);
            cout << A(ans) + in * B(ans) - C(ans) << endl;
        }
    }
    
    return 0;
}
