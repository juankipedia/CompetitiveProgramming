#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 200000;
int N, T, input[MAXN], ans[MAXN];
lli a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0

lli join(lli lval, lli rval){
    return lval + rval;
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


int get(int ss, int se, int si, int i){
    if(ss == se) return ss;
    if(st[L] < i) return get(MID + 1, se, R, i - st[L]);
    else return get(ss, MID, L, i);
}

lli update(int ss, int se, int si, int i, lli val){
    if(ss == se) return a[i] = st[si] = val;
    if(i <= MID) return st[si] = join(update(ss, MID, L, i, val), st[R]);
    else return st[si] = join(st[L], update(MID + 1, se, R, i, val));
}

int main(){
    io_boost;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> input[i];
        for(int i = 0; i < N; i++) a[i] = 1, st[i] = 0;
        build(0, N - 1, 0);
        for(int i = N - 1; i >= 0; i--){
            ans[i] = get(0, N - 1, 0, i - input[i] + 1) + 1;
            update(0, N - 1, 0, ans[i] - 1, 0);
        }

        for(int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << endl;
    }
    
    return 0;
}