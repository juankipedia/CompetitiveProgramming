# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 500005;
int N, g[505][505], p[MAXN], r[MAXN], n;

void solve(int root, vector<int> &leaf){
    int mx = 0;
    for(int l1: leaf)
        for(int l2: leaf)
            mx = max(g[l1][l2], mx);
    vector<vector<int>> children = {{leaf[0]}};
    for(int i = 1; i < leaf.size(); i++){
        int child = -1;
        for(int j = 0; j < children.size(); j++){
            if(g[leaf[i]][children[j][0]] != mx){
                child = j;
                break;
            }
        }
        if(child == -1) children.push_back({leaf[i]});
        else children[child].push_back(leaf[i]);
    }
    r[root] = mx;
    for(int i = 0; i < children.size(); i++){
        if(children[i].size() == 1) p[children[i][0]] = root;
        else{
            p[++n] = root;
            solve(n, children[i]);       
        }
    }
}

int main(){
    io_boost;
    cin >> N;
    vector<int> leaf;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> g[i][j];
            if(i == j) r[i] = g[i][j];
        }
        leaf.push_back(i);
    }
    n = N;
    solve(N, leaf);
    n++;
    cout << n << endl;
    for(int i = 0; i < n; i++) cout << r[i] << " ";
    cout << endl;
    cout << N + 1 << endl;
    for(int i = 0; i < n; i++) if(i != N) cout << i + 1 << " " << p[i] + 1 << endl;
    return 0;
}