#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
const int INF = 1000;

int n, m, t;
int index_i[] = {1, -1, 0, 0}, index_j[] = {0, 0, 1, -1};
queue<int> x;

void bfs(int i, int j, int d[182][182], char g[182][182]){

    int ii, jj, ni, nj;

    d[i][j] = 0;
    x.push(i);
    x.push(j);

    while(!x.empty()){
        ni = x.front();
        x.pop();
        nj = x.front();
        x.pop();
        for(int l = 0; l < 4; l++){
            ii = ni + index_i[l];
            jj = nj + index_j[l];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && (1 + d[ni][nj]) < d[ii][jj] && g[ii][jj] == '0'){
                d[ii][jj] = 1 + d[ni][nj];
                x.push(ii);
                x.push(jj);
            }
        }
    }
}

int main() {
    int d[182][182];
    char g[182][182], ch;

    scanf("%d", &t);
    while(t--){
        scanf("%d%d%c", &n, &m, &ch);
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                scanf("%c", &g[i][j]);
                d[i][j] = INF;
            }
            scanf("%c", &ch);
        }

        for (int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == '1') bfs(i, j, d, g);

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) printf("%d ", d[i][j]);
             printf("\n");
        }
    }
    return 0;
}