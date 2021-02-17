/**
 * KAHN'S ALGORITHM:
 * 
 * Find the linear ordering of vertices (Topological sort) in a directed acyclic graph (DAG).
 * We can also check if the graph has a cycle using kahn's algorithm, if we did not visited all
 * the nodes in the graph, then unvisited nodes will not be at vector<int> toposort, that means
 * if toposort.size() != N then there is a cycle in the graph.
 *
 * time complexity O(N + M).
 * 
 **/

const int MAXN = 1e5;
vector<int> g[MAXN];
int N, M;

vector<int> kahns(){
    vector<int> toposort;
    int in_degree[N] = {0};
    for(int u = 0; u < N; u++)
        for(int v: g[u])
            in_degree[v]++;
    queue<int> q;
    for(int u = 0; u < N; u++)
        if(!in_degree[u]) q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        toposort.push_back(u);
        for(int v: g[u])
            if(--in_degree[v] == 0)
                q.push(v);
    }
    // if toposort.size() != N :  there is a cycle in the graph.
    return toposort;
}
