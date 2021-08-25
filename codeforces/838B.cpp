# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const lli oo = numeric_limits<lli>::max();
const int MAXN = 2e5 + 5;
vector<pair<int, int>> g[MAXN];
vector<tuple<int, int, int>> edges;
int first[MAXN], last[MAXN], n, q, back_edge[MAXN];

vector<int> al;
int firstl[MAXN], heightl[MAXN];

void dfs(int u, int p, int h){
    heightl[u] = h;
    firstl[u] = al.size();
    al.push_back(u);
    for(auto &[v, w] : g[u]){
        if(v != p){
            dfs(v, u, h + 1);
            al.push_back(u);
        }
    }
}   

const int LOG2N = 18;
int lg2[2 * MAXN + 1], st[2 * MAXN][LOG2N + 5];
void build(){
    dfs(0, 0, 0);
    lg2[1] = 0;
    for(int i = 2; i <= al.size(); i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < al.size(); i++) st[i][0] = al[i];
    for(int j = 1; j <= LOG2N; j++){
        for(int i = 0; i + (1 << j) <= al.size(); i++){
            int a = st[i][j - 1], b = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = heightl[a] < heightl[b] ? a : b;
        }
    }
}

int LCA(int u, int v){
    int L = firstl[u], R = firstl[v];
    if(L > R) swap(L, R); 
    int lg = lg2[R - L + 1];
    int l = st[L][lg], r = st[R - (1 << lg) + 1][lg];
    if(heightl[l] < heightl[r]) return l;
    else return r;
}




vector<lli> a, ab;

void dfs(int u, int h){
    first[u] = a.size();
    a.push_back(h);
    ab.push_back(h + back_edge[u]);
    for(auto &[v, w] : g[u]) dfs(v, h + w);
    last[u] = a.size();
    a.push_back(h);
    ab.push_back(h + back_edge[u]);
}   


template<class T> struct SegmentTree{
    
    int N;
    vector<T> st, sta;
    vector<bool> stb;

    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int ss, int se){ return (se + ss) / 2; }
    T NEUTRAL(){ return oo; }

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
        return min(lval, rval);
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
        st[si] += sta[si];
    }

    void set_children(int ss, int se, int si, T val){
        if(ss == se) return;
        sta[L(si)] += val;
        sta[R(si)] += val;
        stb[L(si)] = stb[R(si)] = true;
    }
    void propagate(int ss, int se, int si){
        if(!stb[si]) return;
        operation(ss, se, si); // sets value for st[si] using value in sta[si].
        stb[si] = false;
        set_children(ss, se, si, sta[si]); // sets the value of children given parent si.
        sta[si] = 0;
    }

    void update(int qs, int qe, T val){ return update(0, N - 1, 0, qs, qe, val); }
    void update(int ss, int se, int si, int qs, int qe, T val){
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

    T get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    T get(int ss, int se, int si, int qs, int qe){
        propagate(ss, se, si);
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL();
        return join(get(ss, MID(ss, se), L(si), qs, qe), get(MID(ss, se) + 1, se, R(si), qs, qe));
    }
};

int main(){
    cin >> n >> q;
    for(int i = 0, u, v, w; i < n - 1; i++)
        cin >> u >> v >> w, 
        u--, v--,
        g[u].push_back({v, w}),
        edges.push_back({u, v, w});
    
    for(int i = 0, u, v, w; i < n - 1; i++)
        cin >> u >> v >> w,
        u--, v--,
        back_edge[u] = w,
        edges.push_back({u, v, w});

    dfs(0, 0);
    build();

    SegmentTree<lli> st1(a), st2(ab);

    for(int i = 0, t, a, b; i < q; i++){
        cin >> t >> a >> b;
        a--;
        if(t == 1){
            auto &[u, v, w] = edges[a];
            if(a < (n - 1)) st1.update(first[v], last[v], b - w), st2.update(first[v], last[v], b - w);
            else st2.update(first[u], first[u], b - w), st2.update(last[u], last[u], b - w);
            w = b;
        }
        else{
            int u = a, v = --b;
            int lca = LCA(u, v);
            if(lca == u) cout << abs(st1.get(first[u], first[u]) - st1.get(first[v], first[v])) << endl;
            else cout << st2.get(first[u], last[u]) - st1.get(first[u], first[u]) + st1.get(first[v], first[v]) << endl;
        }
        
    }

    return 0;
}