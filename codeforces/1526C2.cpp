# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = numeric_limits<lli>::max();

const int MAXN = 200005;
int N;
lli st[3 * MAXN], sta[3 * MAXN];
bool stb[3 * MAXN];
 
# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
 
lli join(lli lval, lli rval){
    return min(lval, rval);
}
 
void operation(lli st[], lli sta[], int ss, int se, int si){
    st[si] += sta[si];
}
 
void propagate(int ss, int se, int si){
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
 
void update(int ss, int se, int si, int qs, int qe, lli val){
    propagate( ss, se, si);
    if(ss > qe || se < qs) return;
    if(qs <= ss && se <= qe){
        stb[si] = true;
        sta[si] += val;
        propagate( ss, se, si);
        return;
    }
    update(  ss, MID, L, qs, qe, val);
    update( MID + 1, se, R, qs, qe, val);
    st[si] = join(st[L], st[R]);
}
 
lli get(int ss, int se, int si, int qs, int qe){
    propagate( ss, se, si);
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return oo;
    return join(get( ss, MID, L, qs, qe), get( MID + 1, se, R, qs, qe));
}

int main(){
    cin >> N;
    vector<pair<int, int>> a;
    for(int i = 0, ai; i < N; i++) cin >> ai, a.push_back({ai, i});
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    int ans = 0;
    for(auto &[e, p] : a){
        if(e + get(0, N - 1, 0, p, N - 1) >= 0) ans++, update(0, N - 1, 0, p, N - 1, e);
    }
    cout << ans << endl;
    return 0;
}