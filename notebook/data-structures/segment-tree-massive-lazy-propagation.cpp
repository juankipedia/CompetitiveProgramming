/**
 * 
 * SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 * 
 * for example:
 *  assign value v to all elements on the segment from l to r. (sta[])
 *  find the sum on the segment from l to r. (st[])
 *  
 *  note: additional operation should be distributive.
 *  
 * REQUIRED:
 *      - operation
 *      - join
 * VARIABLES:
 *      st[]: segment tree.
 *      sta[]: lazy propagated segment tree for additional operations.
 *      stb[]: to know if a given node of the segment tree (sta[]) has an operation to be propagated.
 *      a[]: initial array of values.
 *   
 * */

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

void operation(int ss, int se, int si){

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
    operation(ss, se, si); // sets value for st[si] using value in sta[si].
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
    st[si] = join(st[L], st[R]);
}
 
lli get(int ss, int se, int si, int qs, int qe){
    propagate(ss, se, si);
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return NEUTRAL;
    return join(get(ss, MID, L, qs, qe), get(MID + 1, se, R, qs, qe));
}