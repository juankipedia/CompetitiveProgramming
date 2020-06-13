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
int ii[] = {1, -1, 0, 0}, ji[] = {0, 0, 1, -1};
int t, n, m;
string g[50];
int d[50][50];
const int INF = 10000;
 
void dist_(int i, int j){
    queue<int> q;
    q.push(i); q.push(j);
    int ni, nj, ic, jc;
    while(!q.empty()){
        ni = q.front(); q.pop(); nj = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            ic = ni + ii[k]; jc = nj + ji[k];
            if(ic >= 0 && ic < n && jc >= 0 && jc < m && g[ic][jc] != '#'){
                if(d[ni][nj] + 1 < d[ic][jc]){
                    d[ic][jc] = d[ni][nj] + 1;
                    q.push(ic); q.push(jc);
                }
            }
        }
    }
}
 
void dist(int ii, int jj){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = INF;
    d[ii][jj] = 0;
    dist_(ii, jj);
}
 
int main(){
    io_boost;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> g[i];
        
        int pi = -1, pj = -1, bi, bj;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 'B'){
                    bi = i; bj = j;
                    int ni, nj;
                    for(int k = 0; k < 4; k++){
                        ni = i + ii[k]; nj = j + ji[k];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == '.')
                            g[ni][nj] = '#';
                    }
                }
                else if(g[i][j] == 'G'){pi = i; pj = j;}
            }
        }
    
        if(pi == -1 && bi == -1)
            cout << "Yes" << endl;
        else if(pi != -1){
            dist(pi, pj);
            bool ok = d[n - 1][m - 1] != INF;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] == 'G' && d[i][j] == INF) ok = false;
                    else if(g[i][j] == 'B' && d[i][j] != INF) ok = false;
                }
            }
            if(ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            if(g[n - 1][m - 1] != 'B') cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}