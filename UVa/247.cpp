#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string us, vs;
int n, m, ids[25], ti;

void dfs(vector<int> g[], int u, int id, stack<int> &s, bool visited[]){
    visited[u] = true;
    if(id) ids[u] = id;
    for(int v: g[u])
        if(!visited[v]) dfs(g, v, id, s, visited);
    if(!id) s.push(u);
}

void print_connected_components(vector<int> g[], vector<int> gt[], string id_to_names[]){
    stack<int> s;
    bool visited[n] = {false};
    for(int i = 0; i < n; i++)
        if(!visited[i]) dfs(g, i, 0, s, visited);

    for(int i = 0; i < n; i++){
        visited[i] = false;
        ids[i] = 0;
    }

    int id = 1;
    while (!s.empty()){
        int i = s.top();
        s.pop();
        if(!visited[i]){
            dfs(gt, i, id, s, visited);
            //cout << i << " ----------- " << endl;
            id++;
        }
    }

    vector<vector<string>> ans(n + 5);
    for(int i = 0; i < n; i++){
        ans[ids[i]].push_back(id_to_names[i]);
    }
    cout << "Calling circles for data set " << ti << ":" << endl;
    for(int i = 1; i < ans.size(); i++){
        if(ans[i].size()){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j];
                if(j != ans[i].size() - 1) cout << ", ";
            } 
            cout << endl;
        }
    }
}

int main(){
    io_boost;
    ti = 1;
    while(cin >> n >> m && n != 0){
        if(ti != 1) cout << endl;
        vector<int> g[n], gt[n];
        map<string, int> names_to_id;
        string id_to_names[n];
        int id = 0;
        for(int i = 0; i < m; i++){
            cin >> us >> vs;
            if(names_to_id.find(us) == names_to_id.end()){
                names_to_id[us] = id;
                id_to_names[id] = us;
                id++;
            }
            if(names_to_id.find(vs) == names_to_id.end()){
                names_to_id[vs] = id;
                id_to_names[id] = vs;
                id++;
            }
            g[names_to_id[us]].push_back(names_to_id[vs]);
            gt[names_to_id[vs]].push_back(names_to_id[us]);
        }

        print_connected_components(g, gt, id_to_names);
        ti++;
    }
    return 0;
}