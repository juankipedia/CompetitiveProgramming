# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int oo = numeric_limits<int>::max();
const int MAXN = 1e5;
int N, s[MAXN], a[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p){
    if(s[u] == -1){
        int mini = oo;
        for(int v : g[u])
            if(v != p)
                mini = min(mini, s[v]);

        if(s[p] > mini){
            a[u] = -1;
            return;
        }
        if(mini == oo){
            a[u] = 0;
            return;
        }

        a[u] = mini - s[p];
        s[u] = mini;
    }
    else if(p == -1) a[u] = s[u];
    else a[u] = s[u] - s[p];
    for(int v : g[u]) 
        if(v != p)
            dfs(v, u);
}

int main(){
    cin >> N;
    for(int i = 1, pi; i < N; i++){
        cin >> pi;
        pi--;
        g[pi].push_back(i);
        g[i].push_back(pi);
    }
    for(int i = 0; i < N; i++) cin >> s[i];
    dfs(0, -1);
    lli ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}