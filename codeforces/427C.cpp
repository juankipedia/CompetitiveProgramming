#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<lli>::max();
const lli mod = 1000000007;

int n, m, U, V, id[100000], idi;
lli cost[100000];
vector<int> g[100000], gt[100000];
bool visited[100000];
stack<int> s;
pair<lli, int> r[100000];

void dfs(vector<int> g[], int u, bool save){
    visited[u] = true;
    if(!save) id[u] = idi;
    for(int v: g[u])
        if(!visited[v]) dfs(g, v, save);
    if(save) s.push(u);
}

void kosaraju(){
    for(int i = 0; i < n; i++) visited[i] = false;
    for(int i = 0; i < n; i++)
        if(!visited[i]) dfs(g, i, true);
    for(int i = 0; i < n; i++) visited[i] = false;
    idi = 0;
    while(!s.empty()){
        U = s.top();
        if(!visited[U]){ 
            dfs(gt, U, false);
            idi++;
        }
        s.pop();
    }
}

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
        r[i] = {oo, 0};
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> U >> V;
        U--; V--;
        g[U].push_back(V);
        gt[V].push_back(U);
    }

    kosaraju();

    for(int i = 0; i < n; i++){
        lli c = cost[i];
        int d = id[i];
        if(r[d].first > c)
            r[d] = {c, 1};
        else if(r[d].first == c)
            r[d].second++;
    }
    lli tc = 0, ways = 1;
    for(int i = 0; i < n; i++){
        if(r[i].first != oo){
            tc += r[i].first;
            ways = (ways * r[i].second) % mod;
        }
    }
    cout << tc << " " << ways << endl;
    return 0;
}