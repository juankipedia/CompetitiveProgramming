#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 * 
 * KOSARAJU
 * find strongly connected components of a graph.
 * 
 * */

const int MAXN = 100000;
int N, M, component[MAXN], cur_component;
vector<int> g[MAXN], gt[MAXN];
stack<int> s;
bool visited[MAXN];

void dfs(vector<int> g[], int u, bool save){
    visited[u] = true;
    if(!save) component[u] = cur_component;
    for(int v: g[u])
        if(!visited[v]) 
            dfs(g, v, save);
    if(save) s.push(u);
}

void kosaraju(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++)
        if(!visited[i])
            dfs(g, i, true);
    memset(visited, false, sizeof(visited));
    cur_component = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            dfs(gt, u, false);
            cur_component++;
        }
    }
}