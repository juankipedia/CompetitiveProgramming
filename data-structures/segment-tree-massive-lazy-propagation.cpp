/**
 * 
 * SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 * 
 *  Example:
 *  assign value v to all elements on the segment from l to r. (lazy)
 *  find the sum on the segment from l to r. (st)
 *  
 *  note: lazy operation must be distributive.
 *  
 **/

template<class T> struct SegmentTree{
    
    int N;
    vector<T> st, lazy;
    vector<bool> tag;
 
    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int ss, int se){ return (se + ss) / 2; }
    T NEUTRAL(){ return 0; }
 
    SegmentTree(vector<T> &a) : N(a.size()){
        st.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
        tag.assign(4 * N, 0);
        build(a, 0, N - 1);
    }

    SegmentTree(int n) : N(n){
        st.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
        tag.assign(4 * N, 0);
    }
 
    void build(vector<T> &a, int ss, int se, int si = 0){
        if(ss == se){
            st[si] = a[ss];
            return;
        }
        build(a, ss, MID(ss, se), L(si));
        build(a, MID(ss, se) + 1, se, R(si));
        st[si] = st[L(si)] + st[R(si)]; 
    }

 
    void push_down(int ss, int se, int si){
        if(tag[si]){
            st[L(si)] = lazy[si] * (MID(ss, se) - ss + 1);
            st[R(si)] = lazy[si] * (se - MID(ss, se));
            lazy[L(si)] = lazy[R(si)] = lazy[si];
            tag[L(si)] = tag[R(si)] = 1;
            tag[si] = 0;
        }
    }
 
    void update(int qs, int qe, T val){ return update(0, N - 1, 0, qs, qe, val); }
    void update(int ss, int se, int si, int qs, int qe, T val){
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            st[si] = val * (se - ss + 1);
            lazy[si] = val;
            tag[si] = 1;
            return;
        }
        push_down(ss, se, si);
        update(ss, MID(ss, se), L(si), qs, qe, val);
        update(MID(ss, se) + 1, se, R(si), qs, qe, val);
        st[si] = st[L(si)] + st[R(si)];
    }
 
    T get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    T get(int ss, int se, int si, int qs, int qe){
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL();
        push_down(ss, se, si);
        return get(ss, MID(ss, se), L(si), qs, qe) + get(MID(ss, se) + 1, se, R(si), qs, qe);
    }
 
};
