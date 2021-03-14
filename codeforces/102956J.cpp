# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 300005;
int N, M, color[MAXN];;
vector<int> g[MAXN];

int bipartite(int src){
    queue<int> q;
    color[src] = 1;
    q.push(src);
    int b = 1, w = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: g[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                if(color[v] == 1) b++;
                else w++;
                q.push(v);
            }
            else if(color[v] == color[u]) return -1;
        }
    }
    return min(b, w);
}

int main(){
    cin >> N >> M;
    for(int i = 0, x, y; i < M; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(color[i] == -1){
            int c = bipartite(i);
            if(c == -1){
                cout << -1 << endl;
                return 0;
            }
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}