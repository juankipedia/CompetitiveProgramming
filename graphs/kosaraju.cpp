/**
 * 
 * KOSARAJU
 * find strongly connected components of a graph.
 * 
 * */

void dfs(vector<int> g[], stack<int> &s, vector<bool> &visited, vector<int> &component, 
            int &cur_component, int u, bool save){
    visited[u] = true;
    if(!save) component[u] = cur_component;
    for(int v: g[u])
        if(!visited[v]) 
            dfs(g, s, visited, component, cur_component, v, save);
    if(save) s.push(u);
}

vector<int> kosaraju(vector<int> g[], int N){
    
    vector<int> gt[N], component(N);
    int cur_component = 0;
    stack<int> s;
    vector<bool> visited(N, 0);

    for(int u = 0; u < N; u++)
        for(int v : g[u]) gt[v].push_back(u);

    
    for(int i = 0; i < N; i++)
        if(!visited[i])
            dfs(g, s, visited, component, cur_component, i, true);
    
    visited.assign(N, 0);

    cur_component = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u])
            dfs(gt, s, visited, component, cur_component, u, false),
            cur_component++;
    }
    return component;
}