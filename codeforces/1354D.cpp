#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


const int MAXN = 1e6 + 5;
int N;
int a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0

int join(int lval, int rval){
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

int update(int ss, int se, int si, int i, int val){
    if(ss == se) return a[i] = st[si] = val;
    if(i <= MID) return st[si] = join(update(ss, MID, L, i, val), st[R]);
    else return st[si] = join(st[L], update(MID + 1, se, R, i, val));
}

int del(int ss, int se, int si, int i){
    if(ss == se) return a[ss] = st[si] = a[ss] - 1;
    if(st[L] < i) return st[si] = st[L] + del(MID + 1, se, R, i - st[L]);
    else return st[si] = del(ss, MID, L, i) + st[R];
}

int Q;
int main(){
    io_boost;
    cin >> N >> Q;
    for(int i = 0, ai; i < N; i++) cin >> ai, a[--ai]++;
    build(0, N - 1, 0);
    for(int i = 0, ki; i < Q; i++){
        cin >> ki;
        if(ki > 0){
            ki--;
            update(0, N - 1, 0, ki, a[ki] + 1);  
        }
        else{
            ki = abs(ki);
            del(0, N - 1, 0, ki);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i]){
            ans += i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}