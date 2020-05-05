# include <bits/stdc++.h>
 
using namespace std;
int n, m, u, v;
 
void dfs(int i, bool v[], vector<int> G[]){
    if(v[i]) return;
    v[i] = true;
    for(const int &u: G[i]) dfs(u, v, G);
}
 
int f(vector<int> G[]){
    bool v[n + 1] = {false};
    dfs(1, v, G);
    for(int i = 1; i <= n; i++) if(!v[i]) return false;
    return true;
}
 
int main(){
    cin >> n >> m;
    vector<int> G[n + 1];
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if((n - 1) != m) cout << "NO" << endl;
    else{
        if(!f(G)) cout << "NO" << endl;
        else cout << "YES" << endl; 
    }
        
    return 0;
} 