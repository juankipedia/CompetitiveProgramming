/**
 *
 * SEGMENT TREE.
 * O(log(N)) per query.
 * REQUIRED:
 *  - join
 *  - set_node
 *  - NEUTRAL
 * */

template<class T> struct SegmentTree{
    int N;
    vector<T> st;
 
    SegmentTree(vector<T> &a) : N(a.size()){
        st.assign(4 * N, 0);
        build(0, N - 1, 0, a);
    }
 
    SegmentTree(int n) : N(n){ st.assign(4 * N, 0); }
 
    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int ss, int se){ return (ss + se) / 2; }
    T NEUTRAL(){ return 0; }
 
    T join(T lval, T rval){
        return NEUTRAL();
    }
 
    void build(int ss, int se, int si, vector<T> &a){
        if(ss == se){
            st[si] = a[ss];
            return;
        }
        build(ss, MID(ss, se), L(si), a);
        build(MID(ss, se) + 1, se, R(si), a);
        st[si] = join(st[L(si)], st[R(si)]); 
    }
 
    T get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    T get(int ss, int se, int si, int qs, int qe){
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL();
        return join(get(ss, MID(ss, se), L(si), qs, qe), 
                    get(MID(ss, se) + 1, se, R(si), qs, qe));   
    }
    
    // sets new value of st[si] = node in update query
    T set_node(T &node, T val){
        // assign node
        return node;
    }
 
    T update(int i, T val){ return update(0, N - 1, 0, i, val); }
    T update(int ss, int se, int si, int i, T val){
        if(ss == se) return set_node(st[si], val);
        if(i <= MID(ss, se)) return st[si] = join(update(ss, MID(ss, se), L(si), i, val), 
                                                  st[R(si)]);
        else return st[si] = join(st[L(si)], update(MID(ss, se) + 1, se, R(si), i, val));
    }
    
};