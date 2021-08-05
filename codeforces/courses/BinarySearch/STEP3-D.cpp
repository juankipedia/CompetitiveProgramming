# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 100005;
typedef pair<pair<int, int>, int> edge;
int n, m, d;
vector<edge> edges;
vector<int> dist, p;

bool bfs(vector<int> g[]){
    dist.assign(n, MAXN);
    p.assign(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u])
            if(p[v] == -1)
                q.push(v),
                p[v] = u,
                dist[v] = dist[u] + 1;
    }
    return dist[n - 1] <= d;
}

bool check(int k){
    vector<int> g[MAXN];
    for(int i = 0; i < m; i++)
        if(edges[i].second <= k)
            g[edges[i].first.first].push_back(edges[i].first.second);
    return bfs(g);
}

int main(){
    io_boost;
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({{a, b}, c});
    }
    int lo = 0, hi = 1e9 + 5;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    vector<int> g[n];
    for(int i = 0; i < m; i++)
        if(edges[i].second <= lo)
            g[edges[i].first.first].push_back(edges[i].first.second);
    if(lo == 1e9 + 5){
        cout << -1 << endl;
        return 0;
    }
    bfs(g);
    int u = n - 1;
    vector<int> ans;
    while(u != -1){
        ans.push_back(u + 1);
        u = p[u];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() - 1 << endl;
    for(int v : ans) cout << v << " "; 
    cout << endl;
    return 0;
}