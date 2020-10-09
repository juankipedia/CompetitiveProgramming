#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, pair<int, int>> plii;

const lli oo = numeric_limits<lli>::max();
int n, m, I, J, ii[] = {-1, 0, 1};
lli g[10][100], d[10][100];
vector<lli> paths[10][100];

lli dp(int i, int j){
    if(j == m - 1){
        paths[i][j] = {i};
        return d[i][j] = g[i][j];
    }
    if(d[i][j] != -1) return d[i][j];
    lli mini = oo;
    vector<lli> ans;



    set<pair<int, int>> edges;
    int ni, nj;
    for(int l = 0; l < 3; l++){
        ni = i + ii[l]; nj = j + 1;
        if(ni == -1) ni = n - 1;
        else if(ni == n) ni = 0;
        if(nj != m) edges.insert({ni, nj});
    }

    for(auto &p: edges){
        ni = p.first; nj = p.second;
        lli res = dp(ni, nj) + g[i][j]; 
        if(res < mini){
            mini = res;
            ans = paths[ni][nj];
            ans.push_back(i);
        }
    }

    paths[i][j] = ans;
    return d[i][j] = mini;
}

int main(){
    io_boost;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                d[i][j] = -1;
            }
        }
        lli mini = oo;
        int k = 0;
        for(int i = 0; i < n; i++){
            lli res = dp(i, 0);
            if(res < mini){
                mini = res;
                k = i;
            }
        }

        for(int i = paths[k][0].size() - 1; i >= 0; i--){
            cout << paths[k][0][i] + 1;
            if(i != 0)
                cout << " ";
        }
        cout << endl;
        cout << mini << endl;

    }

    return 0;
}