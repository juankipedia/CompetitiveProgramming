/**
 * 
 * SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 * 
 *  Example:
 *  assign value v to all elements on the segment from l to r. (sta)
 *  find the sum on the segment from l to r. (st)
 *  
 *  note: additional operation must be distributive.
 *  
 * REQUIRED:
 *      - set_children
 *      - operation
 *      - join
 *      - NEUTRAL
 * 
 *      For assignment and sum, (assignment is the additional operation):
 * 
 *          T NEUTRAL(){ return 0; }
 *          T join(T lval, T rval){
 *              return lval + rval;
 *          }         
 *          void operation(int ss, int se, int si){
 *              st[si] = (se - ss + 1) * sta[si];
 *          }
 *          void set_children(int ss, int se, int si, T val){
 *              if(ss == se) return;
 *              sta[L(si)] = sta[R(si)] = val;
 *              stb[L(si)] = stb[R(si)] = true;
 *          }
 *              
 *      For addition and minimum, (addition is the additional operation):
 * 
 *          T NEUTRAL(){ return oo; }
 *          T join(T lval, T rval){
 *              return min(lval, rval);
 *          }         
 *          void operation(int ss, int se, int si){
 *              st[si] += sta[si];
 *          }
 *          void set_children(int ss, int se, int si, T val){
 *              if(ss == se) return;
 *              sta[L(si)] += val;
 *              sta[R(si)] += val;
 *              stb[L(si)] = stb[R(si)] = true;
 *          }
 *
 * VARIABLES:
 *      st: segment tree.
 *      sta: lazy propagated segment tree for additional operations.
 *      stb: to know if a given node of the segment tree (sta) has an operation to be propagated.
 *      a: initial array of values.
 *   
 * */

template<class T> struct SegmentTree{
    
    int N;
    vector<T> st, sta;
    vector<bool> stb;

    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int ss, int se){ return (se + ss) / 2; }
    T NEUTRAL(){ return 0; }

    SegmentTree(vector<T> &a) : N(a.size()){
        st.assign(4 * N, 0);
        sta.assign(4 * N, 0);
        stb.assign(4 * N, false);
        build(a, 0, N - 1);
    }

    SegmentTree(int n) : N(n){
        st.assign(4 * N, 0);
        sta.assign(4 * N, 0);
        stb.assign(4 * N, false);
    }

    T join(T lval, T rval){
    }

    void build(vector<T> &a, int ss, int se, int si = 0){
        if(ss == se){
            st[si] = a[ss];
            return;
        }
        build(a, ss, MID(ss, se), L(si));
        build(a, MID(ss, se) + 1, se, R(si));
        st[si] = join(st[L(si)], st[R(si)]); 
    }

    void operation(int ss, int se, int si){
    }

    void set_children(int ss, int se, int si, T val){
    }
    void propagate(int ss, int se, int si){
        if(!stb[si]) return;
        operation(ss, se, si); // sets value for st[si] using value in sta[si].
        stb[si] = false;
        set_children(ss, se, si, sta[si]); // sets the value of children given parent si.
        sta[si] = 0;
    }

    void update(int qs, int qe, lli val){ return update(0, N - 1, 0, qs, qe, val); }
    void update(int ss, int se, int si, int qs, int qe, lli val){
        propagate(ss, se, si);
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            stb[si] = true;
            sta[si] = val;
            propagate(ss, se, si);
            return;
        }
        update(ss, MID(ss, se), L(si), qs, qe, val);
        update(MID(ss, se) + 1, se, R(si), qs, qe, val);
        st[si] = join(st[L(si)], st[R(si)]);
    }

    lli get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    lli get(int ss, int se, int si, int qs, int qe){
        propagate(ss, se, si);
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL();
        return join(get(ss, MID(ss, se), L(si), qs, qe), get(MID(ss, se) + 1, se, R(si), qs, qe));
    }
};
