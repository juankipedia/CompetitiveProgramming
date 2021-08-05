# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
 
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
        return __gcd(lval, rval);
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
};
 
int t, n;
 
bool check(int m, SegmentTree<lli> &st){
    int l = 0, r = m - 1;
    while(r < (n  - 1)){
        if(st.get(l, r) != 1) return true;
        l++;
        r++;
    }
    return false;
}
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<lli> b(n), a(n - 1);
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n - 1; i++)
            a[i] = abs(b[i] - b[i + 1]);
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        SegmentTree<lli> st(a);
        int lo = 0, hi = n;
        while(lo < hi){
            int m = (lo + hi + 1) / 2;
            if(check(m, st)) lo = m;
            else hi = m - 1;
        }
        cout << lo + 1 << endl;
    }
    return 0;
}