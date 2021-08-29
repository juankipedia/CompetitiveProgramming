# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int T, N;
lli C[1005], m[1005], first, second;


lli dfs(int u, int p, lli acc, vector<int> g[]){
    m[u] = acc + C[u];
    for(int v : g[u])
        if(v != p) m[u] = max(dfs(v, u, acc + C[u], g), m[u]);
    return m[u];
}

int main(){
    cin >> T;
    for(int ti = 1; ti <= T; ti++){
        cin >> N;
        vector<int> g[N];
        for(int i = 0; i < N; i++) cin >> C[i];
        for(int i = 0, A, B; i < N - 1; i++){
            cin >> A >> B;
            A--;
            B--;
            g[A].push_back(B);
            g[B].push_back(A);
        }
        first = second = 0;
        dfs(0, -1, 0, g);
        vector<lli> ans;
        for(int c : g[0]) ans.push_back(m[c]);

        cout << "Case #" << ti << ": ";
        sort(ans.begin(), ans.end());

        if(ans.size() > 1) cout << ans[ans.size() - 1] + ans[ans.size() - 2] - C[0] << endl;
        else if(ans.size() == 0) cout << C[0] << endl;
        else cout << ans[0] << endl;
    }
    return 0;
}