/**
 *
 * PRIM'S ALGORITHM
 * find Minimum Spanning Tree (MST).
 * Time complexity O(E log(V))
 * 
 * */

const ll oo = numeric_limits<ll>::max();

const int MAXN = 100000;
int N, M;
vector<pair<ll, int>> g[MAXN];

vector<int> prim(){
    bool in_mst[N] = {false};
    vector<ll> key(N, oo);
    vector<int> parent(N, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        in_mst[u] = true;
        for(auto [w, v]: g[u])
            if(!in_mst[v] && key[v] > w){
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
    }
    return parent;
}
