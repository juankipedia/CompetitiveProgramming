# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2 * 200005;
int N;
lli a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0

lli join(lli lval, lli rval){
    return __gcd(lval, rval);
}

void build(int ss, int se, int si){
    if(ss == se){
        st[si] = a[ss];
        return;
    }
    build(ss, MID, L);
    build(MID + 1, se, R);
    st[si] = join(st[L], st[R]); 
}

lli get(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return NEUTRAL;
    return join(get(ss, MID, L, qs, qe), get(MID + 1, se, R, qs, qe));   
}

lli update(int ss, int se, int si, int i, lli val){
    if(ss == se) return a[i] = st[si] = val;
    if(i <= MID) return st[si] = join(update(ss, MID, L, i, val), st[R]);
    else return st[si] = join(st[L], update(MID + 1, se, R, i, val));
}

int t;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> a[i];
        for(int i = N; i < 2 * N; i++) a[i] = a[i - N];
        int N2 = 2 * N;
        build(0, N2 - 1, 0);
        int lo = 0, hi = N - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            bool ok = true;
            for(int i = 1; i < N; i++)
                if(get(0, N2 - 1, 0, i, i + mid) != get(0, N2 - 1, 0, i - 1, i - 1 + mid)){
                    ok = false;
                    break;
                }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
    return 0;
}