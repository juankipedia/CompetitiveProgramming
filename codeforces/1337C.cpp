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

int n, k, u, v;
vector<int> g[200000];
bool visited[200000], visited_[200000];
int sz[200000], d[200000];
ulli ans[200000];

void bfs() { 
    queue<int> q;
    q.push(0); 
    d[0] = 0;
    visited[0] = true;
    while (!q.empty()) { 
        u = q.front(); 
        q.pop();
        for (const int &e: g[u]) {
            v = e;
            if (!visited[v]){
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v); 
            } 
        } 
    } 
  
} 

void dfs(int i){
    if(visited_[i]) return;
    visited_[i] = true;
    for(const int &e: g[i]){
        if(visited_[e]) continue;
        dfs(e); sz[i] += sz[e]; 
    }
    sz[i]++;
    return; 
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < (n - 1); i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(0);
    bfs();
    for(int i = 0; i < n; i ++) ans[i] = d[i] - (sz[i] - 1);
    sort(ans, ans + n, greater<int>());
    for(int i = 1; i < k; i ++) ans[0] += ans[i];
    cout << ans[0] << endl;
    return 0;
}