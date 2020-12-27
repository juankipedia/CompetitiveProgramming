#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
/**
 * 
 * SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 *
 * REQUIRED:
 *      - operation
 *      - build
 *      - join
 * VARIABLES:
 *      st[]: segment tree for the sum.
 *      sta[]: lazy propagated segment tree.
 *      stb[]: to know if a given node of the segment tree has an operation to be propagated.
 *      a[]: initial array of values.
 *   
 * */

const lli oo = numeric_limits<lli>::max();
const int MAXN = 100000;
int N;
lli st[3 * MAXN], sta[3 * MAXN], a[MAXN];
bool stb[3 * MAXN];
 
# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0
 
lli join(lli lval, lli rval){
    return NEUTRAL;
}

void operation(int si){

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

void propagate(int ss, int se, int si){
    if(!stb[si]) return;
    operation(si);
    stb[si] = false;
    if(ss == se) return;
    sta[L] = sta[R] = sta[si];
    stb[L] = stb[R] = true;
}
 
void update(int ss, int se, int si, int qs, int qe, lli val){
    propagate(ss, se, si);
    if(ss > qe || se < qs) return;
    if(qs <= ss && se <= qe){
        stb[si] = true;
        sta[si] = val;
        propagate(ss, se, si);
        return;
    }
    update(ss, MID, L, qs, qe, val);
    update(MID + 1, se, R, qs, qe, val);
    st[si] = join(st[R], st[L]);
}
 
lli get(int ss, int se, int si, int qs, int qe){
    propagate(ss, se, si);
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return NEUTRAL;
    return join(get(ss, MID, L, qs, qe), get(MID + 1, se, R, qs, qe));
}