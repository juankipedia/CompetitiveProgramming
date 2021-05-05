# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
# define U(t) t.second.first
# define V(t) t.second.second
# define W(t) t.first
typedef pair<lli, pair<int, int>> edge; 
 
const int MAXM = 100005, MAXN = 100005;
edge edges[MAXM], mst[MAXN];
int N, M, p_set[MAXN], w[MAXN];
set<int> s;
 
void build(){
    for(int i = 0; i < N; i++) p_set[i] = i;
}
 
int find(int a){
    if(p_set[a] != a) p_set[a] = find(p_set[a]);
    return p_set[a];
}
 
void join(int a, int b){
    w[find(b)] += w[find(a)];
    p_set[find(a)] = find(b);
}
 
edge ans;
int k;
 
void kruskal(){
    sort(edges, edges + M);
    build();

    for(int i = 0, e = 0; i < N - 1;){
        int u = find(U(edges[e])), v = find(V(edges[e]));
        if(u != v){
            join(u, v);
            if(w[v] == k){
                ans = edges[e];
                break;
            }
            mst[i++] = edges[e];
        }
        e++;
    }
}
 
 
 
int main(){
    cin >> N >> M >> k;
    for(int i = 0, xi; i < k; i++) cin >> xi, w[--xi] = 1;
    lli w;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v >> w;
        edges[i] = {w, {--u, --v}};
    }
    kruskal();
    for(int i = 0; i < k; i++) cout << W(ans) << " ";
    cout << endl;
    return 0;
}