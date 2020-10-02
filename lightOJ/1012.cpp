#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, W, H;
string g[20];
bool v[20][20];
int ii[] = {1, -1, 0, 0}, ij[] = {0, 0, 1, -1};
int dfs(int i, int j){
    v[i][j] = true;
    int s = 1;
    for(int l = 0; l < 4; l++){
        int ni = i + ii[l], nj = j + ij[l];
        if(ni >= 0 && ni < H && nj >= 0 && nj < W && 
            !v[ni][nj] && g[ni][nj] == '.') 
            s += dfs(ni, nj);
    }
    return s;
}

int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> W >> H;
        for(int i = 0; i < H; i++) cin >> g[i];
        int I, J;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(g[i][j] == '@'){
                    I = i; J = j;
                }
                v[i][j] = false;
            }
        }
        cout << "Case " << ti << ": " << dfs(I, J) << endl;
    }
    return 0;
}