#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int m, n;
string g[100];
bool v[100][100];

int ii[] = {1, -1, 1, 1, -1, -1, 0, 0}, ij[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int i, int j){
    v[i][j] = true;
    for(int l = 0; l < 8; l++){
        int ni = i + ii[l], nj = j + ij[l];
        if(ni >= 0 && ni < m && nj >= 0 && nj < n && !v[ni][nj] && g[ni][nj] != '*')
            dfs(ni, nj);
    }
}

int main(){
    io_boost;
    while (cin >> m && cin >> n && m != 0){
        for(int i = 0; i < m; i++) cin >> g[i];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                v[i][j] = false;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!v[i][j] && g[i][j] != '*'){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << endl;
    }
    
    return 0;
}