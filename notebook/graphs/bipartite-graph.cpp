#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *  CHECK WHETHER A GRAPH IS BIPARTITE OR NOT. 
 **/

const int MAXN = 100000;
int N, M;
vector<int> g[MAXN];

bool bipartite(){
    int color[MAXN];
    memset(color, -1, sizeof(color));
    queue<int> q;
    color[0] = 1;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: g[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}
