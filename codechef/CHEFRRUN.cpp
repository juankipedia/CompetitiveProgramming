#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int t;
lli N;
int g[MAXN];
bool visited[MAXN], magic[MAXN], path[MAXN];
int dp(int i){
    visited[i] = true;
    path[i] = true;
    if(path[g[i]]){
        path[i] = false;
        return g[i];
    }
    if(visited[g[i]]){
        path[i] = false;
        return -1;
    }
    int ret = dp(g[i]);
    path[i] = false;
    return ret;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        for(lli i = 0, Ai; i < N; i++){
            cin >> Ai;
            g[i] = (i + Ai + 1) % N;
        }
        int ans = 0;
        memset(visited, false, sizeof(visited));
        memset(path, false, sizeof(path));
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                int init = dp(i);
                if(init == -1) continue;
                int cur = g[init];
                ans++;
                while(cur != init){
                    ans++;
                    cur = g[cur];
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}