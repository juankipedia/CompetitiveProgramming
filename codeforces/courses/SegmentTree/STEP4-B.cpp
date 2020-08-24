#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

# define tup tuple<lli, lli, lli, lli>
# define A(t) get<0>(t)
# define B(t) get<1>(t)
# define C(t) get<2>(t)
# define D(t) get<3>(t)

const lli INF = std::numeric_limits<lli>::max();
int n, m, mod, l, r;
 
lli a[200000], b[200000], c[200000], d[200000];
lli stA[600000], stB[600000], stC[600000], stD[600000];
 
tup multiply(tup &t1, tup &t2){
    return {
        ((A(t1) % mod * A(t2) % mod) % mod + (B(t1) % mod * C(t2) % mod) % mod) % mod, 
        ((A(t1) % mod * B(t2) % mod) % mod + (B(t1) % mod * D(t2) % mod) % mod) % mod,
        ((C(t1) % mod * A(t2) % mod) % mod + (D(t1) % mod * C(t2) % mod) % mod) % mod,
        ((C(t1) % mod * B(t2) % mod) % mod + (D(t1) % mod * D(t2) % mod) % mod) % mod
    };
}

tup build(int ss, int se, int si){
    if(ss == se){
        stA[si] = a[ss]; stB[si] = b[ss];
        stC[si] = c[ss]; stD[si] = d[ss];
        return {a[ss], b[ss], c[ss], d[ss]};
    }
    int mid = ss + (se - ss) / 2;
    tup lt = build(ss, mid, 2 * si + 1), rt = build(mid + 1, se, 2 * si + 2);
    tup ans = multiply(lt, rt);
    stA[si] = A(ans); stB[si] = B(ans);
    stC[si] = C(ans); stD[si] = D(ans);
    return ans;
}
 
tup get_product(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return {stA[si], stB[si], stC[si], stD[si]};
    if(qs > se || ss > qe) return {INF, INF, INF, INF};
    int mid = ss + (se - ss) / 2;
    tup lt = get_product(ss, mid, 2 * si + 1, qs, qe), rt = get_product(mid + 1, se, 2 * si + 2, qs, qe);
    tup ans;
    if(A(lt) == INF) ans = rt;
    else if(A(rt) == INF) ans = lt;
    else ans = multiply(lt, rt);
    return ans;
}
 
 
int main(){
    io_boost;
    cin >> mod >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    build(0, n - 1, 0);
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        l--; r--;
        tup ans = get_product(0, n - 1, 0, l, r);
        cout << A(ans) << " " << B(ans) << endl;
        cout << C(ans) << " " << D(ans) << endl;
        cout << endl;
    }
    return 0;
}