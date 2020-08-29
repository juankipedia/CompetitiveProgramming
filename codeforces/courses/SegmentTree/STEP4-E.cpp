#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long int ll;
const ll I = numeric_limits<ll>::max();
int n, m, q, t, l, r;
ll h, st[300000];
 
void build(int ss, int se, int si){
    if(ss == se){ st[si] = I; return; }
    int mid = ss + (se - ss) / 2;
    st[si] = I;
    build(ss, mid, 2 * si + 1); 
    build(mid + 1, se, 2 * si + 2);
}
 
int destroy(int ss, int se, int si, int qs, int qe, ll p){
    if(qs > se || ss > qe) return 0;
    if(ss == se){ st[si] = I; return 1; }
    int mid = ss + (se - ss) / 2, ans = 0;
    if(st[2 * si + 1] <= p) 
        ans += destroy(ss, mid, 2 * si + 1, qs, qe, p);
    if(st[2 * si + 2] <= p)
        ans += destroy(mid + 1, se, 2 * si + 2, qs, qe, p);
    st[si] = min(st[2 * si + 1], st[2 * si + 2]);
    return ans;
}
 
ll construct(int ss, int se, int si, int i, ll v){
    if(i < ss || i > se) return st[si];
    if(ss == se) return st[si] = v;
    int mid = ss + (se - ss) / 2;
    return st[si] = min(construct(ss, mid, 2 * si + 1, i, v), 
                            construct(mid + 1, se, 2 * si + 2, i, v));
}

int main(){
    io_boost;
    cin >> n >> m;
    build(0, n - 1, 0);
    while(m--){
        cin >> t;
        if(t == 1){
            cin >> l >> h;
            construct(0, n - 1, 0, l, h);
        }
        else{
            cin >> l >> r >> h;
            cout << destroy(0, n - 1, 0, l, r - 1, h) << endl;
        }
    }
    return 0;
}