# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, ii[] = {0, 0, 1, -1}, jj[] = {1, -1, 0, 0};
string g[55];
bool v[55][55];


int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> g[i];
        bool ok = true;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) v[i][j] = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(g[i][j] != '.'){
                    queue<int> q;
                    q.push(i);
                    q.push(j);
                    while(!q.empty()){
                        int r = q.front(); q.pop();
                        int c = q.front(); q.pop();
                        for(int k = 0; k < 4; k++){
                            int nr = ii[k] + r, nc = jj[k] + c;
                            if(nr < 0 || nr >= n || nc < 0 || nc >= m || v[nr][nc]) continue;
                            if(g[nr][nc] == '.'){
                                if(g[r][c] == 'W') g[nr][nc] = 'R';
                                else g[nr][nc] = 'W';
                            }
                            else if(g[r][c] == g[nr][nc]){ ok = false; break; }
                            q.push(nr); q.push(nc);
                            v[nr][nc] = true;
                        }
                    }
                }
            if(!ok) break;
        }
        if(g[0][0] == '.' && ok){
            g[0][0] = 'R';
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)
                    if(g[i][j] != '.'){
                        queue<int> q;
                        q.push(i);
                        q.push(j);
                        while(!q.empty()){
                            int r = q.front(); q.pop();
                            int c = q.front(); q.pop();
                            for(int k = 0; k < 4; k++){
                                int nr = ii[k] + r, nc = jj[k] + c;
                                if(nr < 0 || nr >= n || nc < 0 || nc >= m || v[nr][nc]) continue;
                                if(g[nr][nc] == '.'){
                                    if(g[r][c] == 'W') g[nr][nc] = 'R';
                                    else g[nr][nc] = 'W';
                                }
                                else if(g[r][c] == g[nr][nc]){ ok = false; break; }
                                q.push(nr); q.push(nc);
                                v[nr][nc] = true;
                            }
                        }
                    }
                if(!ok) break;
            }
        }
        if(ok){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) cout << g[i] << endl;
        }
        else cout << "NO" << endl;
    }   
    return 0;
}