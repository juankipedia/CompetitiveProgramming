#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli INF = numeric_limits<lli>::max();
int L, R, n, m, t;
lli sta[300000], st[300000], V;
bool stab[300000];

void assign(int ss, int se, int si, int l, int r, int v){
    if(l <= ss && se <= r){
        sta[si] = v;
        stab[si] = true;
        return;
    }
    if(se < l || ss > r) return;
    if(stab[si]){
        stab[si] = false;
        sta[2 * si + 1] = sta[2 * si + 2] = sta[si];
        stab[2 * si + 1] = stab[2 * si + 2] = true;
    }
    int mid = ss + (se - ss) / 2;
    assign(ss, mid, 2 * si + 1, l, r, v);
    assign(mid + 1, se, 2 * si + 2, l, r, v);
    lli L = stab[2 * si + 1] ? sta[2 * si + 1] : st[2 * si + 1];
    lli R = stab[2 * si + 2] ? sta[2 * si + 2] : st[2 * si + 2];
    st[si] = min(R, L);
    return;
}

lli get_min(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r){
        if(stab[si]) return sta[si];
        else return st[si];
    }
    if(se < l || ss > r) return INF;
    int mid = ss + (se - ss) / 2;
    //if(ss == 0 && se == 2) cout << stab[si] << " " << sta[si] << endl;
    if(stab[si]) return sta[si];
    lli L = get_min(ss, mid, 2 * si + 1, l, r);
    lli R = get_min(mid + 1, se, 2 * si + 2, l, r);
    return min(L, R);
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
        else{
            cin >> L >> R;
            cout << get_min(0, n - 1, 0, L, R - 1) << endl;
        }
    }
 
    return 0;
}