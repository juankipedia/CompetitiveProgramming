#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N;
lli a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 1

lli join(lli lval, lli rval){
    return lval * rval;
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

int K, l, r;
lli val;
string q;

int main(){
    io_boost;
    while(cin >> N >> K){
        for(int i = 0; i < N; i++){
            cin >> a[i];
            if(a[i] > 0) a[i] = 1;
            else if(a[i] < 0) a[i] = -1;
            else a[i] = 0;
        }
        build(0, N - 1, 0);
        for(int i = 0; i < K; i++){
            cin >> q;
            if(q == "C"){
                cin >> l >> val;
                l--;
                            if(val > 0) val = 1;
            else if(val < 0) val = -1;
            else val = 0;
                update(0, N - 1, 0, l, val);
            }
            else{
                cin >> l >> r;
                l--; r--;
                val = get(0, N - 1, 0, l, r);
                //cout << ")))))) " << val << endl;
                if(val < 0) cout << "-";
                else if(val > 0) cout << "+";
                else cout << "0";
            }
        }
        cout << endl;
    }
    
    return 0;
}