# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int get(char c){ return c - 'A'; };
vector<int> g[26];
int d[26][26];

void bfs(int s){
    queue<int> q;
    q.push(s);
    d[s][s] = 0;
    bool visited[26] = {false};
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(visited[v]) continue;
            visited[v] = true;
            d[s][v] = d[s][u] + 1;
            q.push(v);
        }
    }
}

int main(){
    io_boost;
    int t, k;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        string s;
        cin >> s;
        for(int i = 0; i < 26; i++){
            g[i].clear();
            for(int j = 0; j < 26; j++) d[i][j] = 1e9;
        }
        cin >> k;
        string e;
        for(int i = 0; i < k; i++) 
            cin >> e,
            g[get(e[0])].push_back(get(e[1]));
        for(int i = 0; i < 26; i++)
            bfs(i);
        lli ans = 1e9;
        for(int i = 0; i < 26; i++){
            lli res = 0;   
            for(int j = 0; j < s.size(); j++){
                int c = get(s[j]);
                if(i == c) continue;
                res += d[c][i];
            }
            ans = min(res, ans);
        }
        cout << "Case #" << ti << ": ";
        if(ans >= 1e9) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}