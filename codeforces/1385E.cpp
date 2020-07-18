#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int v_v[200000], u_v[200000], q, n, m, t, u, v;


void topo_sort(int v, vector<bool> &visited, stack<int> &s, vector<int> g[]){
    if(visited[v]) return;
    visited[v] = true;
    for(const int &u: g[v])
        topo_sort(u, visited, s, g);
    s.push(v);
}

int main(){
    io_boost;
    cin >> q;
    while (q--){
        cin >> n >> m;
        vector<int> g[n];
        for(int i = 0; i < m; i++){
            cin >> t >> u >> v;
            u--; v--;
            if(t)
                g[u].push_back(v);
            u_v[i] = u; v_v[i] = v;
        }
        vector<bool> visited(n); stack<int> s;
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                topo_sort(i, visited, s, g);
        
        vector<int> p(n); int j = 0;
        while(!s.empty()){p[s.top()] = j; s.pop(); j++;}

        bool ok = true;
        for(int i = 0; i < n; i++)
            for(const int &j: g[i])
                if(p[i] > p[j]){ok = false; break;}
        if(!ok){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0; i < m; i++)
            if(p[u_v[i]] < p[v_v[i]])
                cout << u_v[i] + 1 << " " << v_v[i] + 1 << endl;
            else
                cout << v_v[i] + 1 << " " << u_v[i] + 1 << endl;
    }
    
    return 0;
}