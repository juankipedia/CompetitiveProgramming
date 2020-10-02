#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int R, C;
string r;
char g[2005][2005];
int ii[] = {1, -1, 0, 0}, ij[] = {0, 0, 1, -1};
bool v[2005][2005];

char dfs(int i, int j, char c){
    v[i][j] = true;
    g[i][j] = c;
    if(i == 0 || i == R - 1 || j == 0 || j == C - 1) g[i][j] = '.';
    for(int k = 0; k < 4; k++){
        int ni = ii[k] + i, nj = ij[k] + j;
        if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
        if(g[ni][nj] == '.' && !v[ni][nj]){
            if(dfs(ni, nj, g[i][j]) == '.')
                g[i][j] = '.';
        }
    }
    return g[i][j];
}

void dfs2(int i, int j){
    v[i][j] = true;
    g[i][j] = '.';
    for(int k = 0; k < 4; k++){
        int ni = ii[k] + i, nj = ij[k] + j;
        if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
        if(g[ni][nj] == ',' && !v[ni][nj]) dfs2(ni, nj);
    }
}

int main(){
    io_boost;
    cin >> R >> C;
    memset(g, '.', sizeof g);
    int k = 0;
    for(int i = 0; i < R; i++){
        cin >> r;
        k = i * 2 + 1;
        g[k][0] = '.';
        g[k + 1][0] = '.';
        for(int j = 0; j < C; j++){
            if(r[j] == '/'){
                g[k][j * 2 + 1] = '.'; g[k][j * 2 + 2] = '/';
                g[k + 1][j * 2 + 1] = '/'; g[k + 1][j * 2 + 2] = '.';
            }
            else if(r[j] == '\\'){
                g[k][j * 2 + 1] = '\\'; g[k][j * 2 + 2] = '.';
                g[k + 1][j * 2 + 1] = '.'; g[k + 1][j * 2 + 2] = '\\';
            }
            else{
                g[k][j * 2 + 1] = '.'; g[k][j * 2 + 2] = '.';
                g[k + 1][j * 2 + 1] = '.'; g[k + 1][j * 2 + 2] = '.';
            }
        }
        g[k][2 * C + 1] = '.';
        g[k + 1][2 * C + 1] = '.';
    }

    R = R * 2 + 2;
    C = C * 2 + 2;


    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(g[i][j] == '.' && !v[i][j])
                dfs(i, j, ',');

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++) v[i][j] = false;
    

    int ans = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(g[i][j] == ',' && !v[i][j]){
                dfs2(i, j);
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}