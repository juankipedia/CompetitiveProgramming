/**
 *
 * SEGMENT TREE.
 * O(log(N)) per query.
 * REQUIRED:
 *  - join
 * */


template<class T> struct SegmentTree{
    int N;
    vector<T> st;

    SegmentTree(vector<T> &a){
        N = a.size();
        st.resize(3 * (N + 5), 0);
        build(0, N - 1, 0, a);
    }

    SegmentTree(int n){
        N = n;
        st.resize(3 * (N + 5), 0);
    }

    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int si){ return (ss + se) / 2; }
    T NEUTRAL(){ return 0; }

    T join(T lval, T rval){
        return NEUTRAL;
    }

    void build(int ss, int se, int si, vector<T> &a){
        if(ss == se){
            st[si] = a[ss];
            return;
        }
        build(ss, MID, L);
        build(MID + 1, se, R);
        st[si] = join(st[L], st[R]); 
    }

    T get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    T get(int ss, int se, int si, int qs, int qe){
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL;
        return join(get(ss, MID, L, qs, qe), get(MID + 1, se, R, qs, qe));   
    }

    T update(int i, T val){ return update(0, N - 1, 0, i, val); }
    T update(int ss, int se, int si, int i, T val){
        if(ss == se) return st[si] = val;
        if(i <= MID) return st[si] = join(update(ss, MID, L, i, val), st[R]);
        else return st[si] = join(st[L], update(MID + 1, se, R, i, val));
    }

};