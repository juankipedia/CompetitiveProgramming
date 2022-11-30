/**
 *
 * PRIM'S ALGORITHM
 * find Minimum Spanning Tree (MST).
 * Time complexity O(E log(V))
 * 
 * */

const lli oo = numeric_limits<lli>::max();

const int MAXN = 100000;
int N, M;
vector<pair<lli, int>> g[MAXN];

vector<int> prim(){
    bool in_mst[N] = {false};
    vector<lli> key(N, oo);
    vector<int> parent(N, -1);
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
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