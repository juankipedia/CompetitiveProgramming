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
const lli INF = numeric_limits<lli>::max();
int n, b[200000], c[200000], u, v, cnt[200000];
lli a[200000], cost;
vector<int> g[200000];
bool vbfs[200000], vdp[200000];

pair<int, int> bfs(int node, int parent, lli mini){
    pair<int, int> ans = {0, 0};
    if(b[node] != c[node] && b[node] == 1) ans.first++;
    else if(b[node] != c[node]) ans.second++;

    for(const int &child : g[node]){
        if(child == parent) continue;
        auto p = bfs(child, node, min(mini, a[node]));
        ans.first += p.first;
        ans.second += p.second;
    }

    if(a[node] < mini){
        auto s = min(ans.first, ans.second);
        cost += 2 * s * a[node];
        ans.first -= s;
        ans.second -= s;
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 0; i < (n - 1); i++){
        cin >> u >> v;
        u --; v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto ans = bfs(0, -1, INF);
    if(ans.first != 0 || ans.second != 0)
        cout << -1 << endl;
    else 
        cout << cost << endl;
    return 0;
}