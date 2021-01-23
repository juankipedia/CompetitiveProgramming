#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


# define NEUTRAL 0

struct Node{
    Node *left = nullptr, *right = nullptr;
    lli st = 0, sta = 0;
    bool stb = false;
    lli ss, se;

    Node(lli ss, lli se): ss(ss), se(se){}

    lli mid(){ return ss + (se - ss) / 2; }
    
    lli join(lli lval, lli rval){
        return lval + rval;
    }

    void operation(){
        st += (se - ss + 1) * sta;
    }

    void propagate(){
        if(left == nullptr && right == nullptr){
            left = new Node(ss, mid());
            right = new Node(mid() + 1, se);
        }
        if(!stb) return;
        operation(); // sets value for st using value in sta.
        stb = false;
        if(ss == se){
            sta = 0;
            return;
        }
        left->sta += sta;
        right->sta += sta;
        left->stb = right->stb = true;
        sta = 0;
    }

    void update(lli qs, lli qe, lli val){
        propagate();
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            stb = true;
            sta += val;
            propagate();
            return;
        }
        left->update(qs, qe, val);
        right->update(qs, qe, val);
        st = join(left->st, right->st);
    }

    lli get(lli qs, lli qe){
        propagate();
        if(qs <= ss && se <= qe) return st;
        if(ss > qe || se < qs) return NEUTRAL;
        return join(left->get(qs, qe), right->get(qs, qe));
    }
};

const int MAXN = 3e5 + 5;
int N, M;
vector<int> g[MAXN];
vector<pair<lli, lli>> q[MAXN];
lli ans[MAXN];
Node segtree(0, MAXN + 1e9);

void dfs(int u, int p, int h){
    for(auto &e: q[u])
        segtree.update(h, h + e.first, e.second);
    ans[u] = segtree.get(h, h);
    for(int v : g[u])
        if(v != p)
            dfs(v, u, h + 1);
    for(auto &e: q[u])
        segtree.update(h, h + e.first, -e.second);
   
}

int main(){
    io_boost;
    cin >> N;
    for(int i = 0, u, v; i < N - 1; i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> M;
    lli d, x;
    for(int i = 0, v; i < M; i++){
        cin >> v >> d >> x;
        v--;
        q[v].push_back({d, x});
    }
    dfs(0, -1, 0);
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}