#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int m, n, u, v;
vector<int> g[100000];
lli d[100000];
bool visited[100000];

int main(){
    io_boost;
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v: g[u]){
            if(!visited[v]){
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    cout << d[n - 1] - 1 << endl;
    return 0;
}