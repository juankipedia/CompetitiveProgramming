#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int n, m, u, v, n_scc;
vector<int> g[100000], gt[100000];
stack<int> s;
vector<set<int>> scc;
void dfs_(vector<int> g_[], int src, bool visited[], bool f){
    visited[src] = true;
    if(!f) scc[n_scc].insert(src);

    for(const int &tgt: g_[src]){
        if(visited[tgt]) continue;
        dfs_(g_, tgt, visited, f);
    }
    
    if(f) s.push(src);
}

void dfs(){
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    for(int i = 0; i < n; i++)
        if(!visited[i]) dfs_(g, i, visited, true);
}

void k(){
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    n_scc = 0;
    while(!s.empty()){
        u = s.top(); s.pop();
        if(visited[u]) continue;
        scc.push_back({});
        dfs_(gt, u, visited, false);
        n_scc++;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    dfs();
    k();
    for(int i = 0; i < n; i++){
        for(const auto &st: scc){
            if(st.find(i) != st.end()){
                cout << *st.begin() << endl;
                break;
            }
        }
    }
    return 0;
}