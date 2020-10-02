#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef tuple<int, int, int> tup;

# define ancestor(t) get<1>(t)
# define parent(t) get<2>(t)
# define distance(t) get<0>(t)

const lli oo = numeric_limits<lli>::max();
int m, n, u, v, h, k;
vector<int> g[3000];
lli d[3000][3000];
int p[3000][3000];
map<int, map<int, set<int>>> r;

int main(){
    io_boost;
    cin >> n >> m >> k;
    while (m--){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while(k--){
        cin >> u >> v >> h;
        u--; v--; h--;
        r[u][v].insert(h);
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = oo;
    
    queue<tup> q;
    q.push({0, 0, 0});
    d[0][0] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();    
        for(int v: g[parent(t)]){
            if(r[ancestor(t)][parent(t)].find(v) == r[ancestor(t)][parent(t)].end() &&
                d[parent(t)][v] >  d[ancestor(t)][parent(t)] + 1){
                d[parent(t)][v]  =  d[ancestor(t)][parent(t)] + 1;
                p[parent(t)][v] = ancestor(t);
                q.push({d[parent(t)][v], parent(t), v});
            }
        }
    }

    lli sd = oo, prev = -1;
    for(int i = 0; i < n; i++){
        if(d[i][n - 1] < sd){
            sd = d[i][n - 1];
            prev = i;
        }
    }
    if(prev == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << sd << endl;
    int x = prev, y = n - 1;
    vector<int> sp;
    while(y != 0){
        sp.push_back(y + 1);
        int aux = p[x][y];
        y = x;
        x = aux;
    }
    sp.push_back(1);
    for(int i = sp.size() - 1; i >= 0; i--) cout << sp[i] << " ";
    cout << endl;
    return 0;
}