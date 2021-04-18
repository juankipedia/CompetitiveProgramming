# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


const int MAXN = 500005;
int N, K;
lli st[5 * MAXN], sta[5 * MAXN], a[MAXN];
bool stb[5 * MAXN];
 
# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0
 
lli join(lli lval, lli rval){
    return lval + rval;
}
 
void operation(lli st[], lli sta[], int ss, int se, int si){
    st[si] += (se - ss + 1) * sta[si];
}
 
void propagate(int ss, int se, int si){
    if(!stb[si]) return;
    operation(st, sta, ss, se, si); // sets value for st[si] using value in sta[si].
    stb[si] = false;
    if(ss == se){
        sta[si] = 0;
        return;
    }
    sta[L]+= sta[si];
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
    if(ss > qe || se < qs) return NEUTRAL;
    return join(get( ss, MID, L, qs, qe), get( MID + 1, se, R, qs, qe));
}

int t;

int main(){
    io_boost;
    cin >> t;
    while(t--){

        

        cin >> N >> K;

        for(int i = 0; i < 4 * 2 * K; i++) sta[i] = st[i] = stb[i] = 0;

        for(int i = 0; i < N; i++) cin >> a[i];

        for(int i = 0; i < N / 2; i++){
            lli l = min(a[i], a[N - i - 1]) + 1, r = max(a[i], a[N - i - 1]) + K;
            if((a[i] + a[N - i - 1] - 1) >= l) update(0, 2 * K + 1, 0, l, a[i] + a[N - i - 1] - 1, 1);
            if((a[i] + a[N - i - 1] + 1) <= r) update(0, 2 * K + 1, 0, a[i] + a[N - i - 1] + 1, r, 1);
            update(0, 2 * K + 1, 0, 0, l - 1, 2);
            update(0, 2 * K + 1, 0, r + 1, 2 * K + 1, 2);
        }
        lli mini = MAXN * 8;

        for(int i = 1; i <= 2 * K; i++){
           
                mini = min(get(0, 2 * K + 1, 0, i, i), mini);


        }
        cout << mini << endl;
    }
    return 0;
}
