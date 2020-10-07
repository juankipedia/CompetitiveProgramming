#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, u, v;

void dfs(vector<int> g[], int u, bool v[], stack<int> &s){
    v[u] = true;
    for(int e: g[u])
        if(!v[e]) dfs(g, e, v, s);
    s.push(u);
};

void toposort(vector<int> g[]){
    bool v[n] = {false};
    stack<int> s;
    for(int i = 0; i < n; i++)
        if(!v[i]) dfs(g, i, v, s);
    while(!s.empty()){
        cout << s.top() + 1 << " ";
        s.pop();
    }
    cout << endl;
    return;
}

int main(){
    io_boost;
    while(cin >> n >> m && n != 0){
        vector<int> g[n];
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
        }
        toposort(g);
    }
    
    return 0;
}