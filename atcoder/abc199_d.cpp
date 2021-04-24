# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
const int MAXN = 25;
int N, M;
vector<int> g[MAXN];
int color[MAXN], lvl[MAXN];
bool visited[MAXN];
 
lli go(int u){
    visited[u] = true;
    lli ret = 1;
    for(int v: g[u]){
        if(lvl[v] != 0 && lvl[v] != lvl[u] + 1){
            if(color[v] == color[u]) ret = 0;
            continue;
        }
        lvl[v] = lvl[u] + 1;
        lli ans = 0;
        for(int i = 1; i <= 3; i++){
            if(i != color[u]){
                color[v] = i;
                ans += go(v);
            }
        }
        color[v] = 0;
        ret *= ans;
    }
    return ret;
}
 
 
int main(){
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    lli ans = 1;
    for(int i = 0; i < N; i++)
        if(!visited[i]){
            lvl[i] = 1;
            color[i] = 1;
            ans *= 3 * go(i);
            color[i] = 0;
        }
    cout << ans << endl;
    return 0;
}