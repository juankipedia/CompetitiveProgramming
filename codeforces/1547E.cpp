# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli oo = numeric_limits<lli>::max();
 
const int MAXN = 3000005;
int N;

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
 
lli join(lli lval, lli rval){
    return min(lval, rval);
}
 
void operation(lli st[], lli sta[], int ss, int se, int si){
    st[si] += sta[si];
}

void build(lli st[], lli a[], int ss, int se, int si){
    if(ss == se){
        st[si] = a[ss];
        return;
    }
    build(st, a, ss, MID, L);
    build(st, a, MID + 1, se, R);
    st[si] = join(st[L], st[R]); 
}

void propagate(lli st[], lli sta[], bool stb[], int ss, int se, int si){
    if(!stb[si]) return;
    operation(st, sta, ss, se, si); // sets value for st[si] using value in sta[si].
    stb[si] = false;
    if(ss == se){
        sta[si] = 0;
        return;
    }
    sta[L] += sta[si];
    sta[R] += sta[si];
    stb[L] = stb[R] = true;
    sta[si] = 0;
}
 
void update(lli st[], lli sta[], bool stb[], int ss, int se, int si, int qs, int qe, lli val){
    propagate(st, sta, stb, ss, se, si);
    if(ss > qe || se < qs) return;
    if(qs <= ss && se <= qe){
        stb[si] = true;
        sta[si] += val;
        propagate(st, sta, stb, ss, se, si);
        return;
    }
    update(st, sta, stb, ss, MID, L, qs, qe, val);
    update(st, sta, stb, MID + 1, se, R, qs, qe, val);
    st[si] = join(st[L], st[R]);
}
 
lli get(lli st[], lli sta[], bool stb[], int ss, int se, int si, int qs, int qe){
    propagate(st, sta, stb, ss, se, si);
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return oo;
    return join(get(st, sta, stb, ss, MID, L, qs, qe), get(st, sta, stb, MID + 1, se, R, qs, qe));
}
 

int q, k;
lli a[MAXN], t[MAXN];

lli st1[3 * MAXN], sta1[3 * MAXN], a1[MAXN];
lli st2[3 * MAXN], sta2[3 * MAXN], a2[MAXN];
bool stb1[3 * MAXN];
bool stb2[3 * MAXN];

int main(){
    io_boost;
    cin >> q;
    while(q--){
        cin >> N >> k;
        for(int i = 0; i < (3 * N) + 15; i++) st1[i] = st2[i] = sta1[i] = sta2[i] = 0, stb1[i] = stb2[i] = false;
        bool done[N] = {false};
        for(int i = 0; i < k; i++) cin >> a[i], a[i]--;
        for(int i = 0; i < k; i++) cin >> t[i];
        for(int i = 0; i < k; i++){
            a1[a[i]] = t[i] - a[i];
            a2[a[i]] = t[i] + a[i];
            done[a[i]] = true;
        }
        for(int i = 0; i < N; i++) if(!done[i]) a1[i] = a2[i] = 1e16;
        build(st1, a1, 0, N - 1, 0);
        build(st2, a2, 0, N - 1, 0);
        for(int i = 0; i < N; i++){
            update(st1, sta1, stb1, 0, N - 1, 0, 0, i, i);
            update(st2, sta2, stb2, 0, N - 1, 0, i, N - 1, -i);
            cout << min(get(st1, sta1, stb1, 0, N - 1, 0, 0, i), 
                        get(st2, sta2, stb2, 0, N - 1, 0, i, N - 1)) << " ";
            update(st1, sta1, stb1, 0, N - 1, 0, 0, i, -i);
            update(st2, sta2, stb2, 0, N - 1, 0, i, N - 1, i);
        }
        cout << endl; 
    }
    return 0;
}