# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m;
int ii[] = {0, 0, 1, -1}, jj[] = {1, -1, 0, 0};
string g[1005];
vector<bool> visited;
int dp[1005][1005][4][3];
bool dfs(int i, int j, int d, int t){
    if(t >= 3) return false;
    if(g[i][j] == 'T') return true;
    if(dp[i][j][d][t] != -1) return dp[i][j][d][t];
    dp[i][j][d][t] = 0;
    for(int k = 0; k < 4; k++){
        int ni = i + ii[k], nj = j + jj[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] != '*'){
            int ti = t;
            if(d != k) ti++;
            if(dfs(ni, nj, k, ti)){
                dp[i][j][d][t] = 1;
                break;
            };
        }
    }
    return dp[i][j][d][t];
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'S'){
                // d0: R, d1: L, d2: D, d3: U
                for(int d = 0; d < 4; d++){
                    if(dfs(i, j, d, 0)){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    return 0;
}