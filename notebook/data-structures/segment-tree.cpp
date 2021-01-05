#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * SEGMENT TREE.
 * O(log(N)) per query.
 * REQUIRED:
 *  - join
 * */

const int MAXN = 100000;
int N;
lli a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0

lli join(lli lval, lli rval){
    return NEUTRAL;
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