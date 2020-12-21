#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int MAXN = 1000;

int t, N, M, q, first[MAXN], height[MAXN];
vector<int> g[MAXN], a;

void dfs(int u, int p, int h){
    height[u] = h;
    first[u] = a.size();
    a.push_back(u);
    for(int v: g[u]){
        if(v != p){
            dfs(v, u, h + 1);
            a.push_back(u);
        }
    }
}   

const int LOG2N = 11;
int lg2[2 * MAXN + 1], st[2 * MAXN][LOG2N + 5];

void build(){
    dfs(0, 0, 0);
    lg2[1] = 0;
    for(int i = 2; i <= a.size(); i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < a.size(); i++) st[i][0] = a[i];
    for(int j = 1; j <= LOG2N; j++){
        for(int i = 0; i + (1 << j) <= a.size(); i++){
            int a = st[i][j - 1], b = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = height[a] < height[b] ? a : b;
        }
    }
}

int LCA(int u, int v){
    int L = first[u], R = first[v];
    if(L > R) swap(L, R); 
    int lg = lg2[R - L + 1];
    int l = st[L][lg], r = st[R - (1 << lg) + 1][lg];
    if(height[l] < height[r]) return l;
    else return r;
}


int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> N;
        a.clear();
        for(int i = 0; i < N; i++) g[i] = {};
        for(int i = 0, n; i < N; i++){
            cin >> n;
            for(int j = 0, v; j < n; j++){
                cin >> v;
                v--;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }
        build();
        cin >> q;
        cout << "Case " << ti << ":" << endl;
        for(int i = 0, u, v; i < q; i++){
            cin >> u >> v;
            u--; v--;
            cout << LCA(u, v) + 1 << endl;
        }
    }   
    return 0;
}