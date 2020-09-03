#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const ulli mod = 1e9 + 7;
ulli n;
int t, u, v, m;

int count_childs(vector<int> g[], bool visited[], vector<ulli> &cnt, int node){
    ulli count = 1;
    visited[node] = true;
    for(const int &child: g[node]){
        if(!visited[child])
            count += count_childs(g, visited, cnt, child);
    }
    if(count != n) cnt.push_back((n - count) * count);
    return count;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> g[n];
        vector<ulli> cnt, p;
        bool visited[n] = {false};
        for(int i = 0; i < (n - 1); i++){
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin >> m;
        p.resize(m);
        for(int i = 0; i < m; i++) cin >> p[i];
        sort(p.begin(), p.end());
        while(p.size() > (n - 1)){
            ulli k = p.back(); p.pop_back(); 
			ulli k2 = p.back(); p.pop_back();
			p.push_back((k % mod * k2 % mod) % mod);
        }
        for(int i = 0; i < n; i++)
            if(!visited[i]) 
                count_childs(g, visited, cnt, i);
        sort(cnt.begin(), cnt.end(), std::greater<ulli>());
        reverse(p.begin(), p.end());
        ulli ans = 0;
        for(int i = 0; i < cnt.size(); i++){
            ulli pi = 1;
            if(i < m) pi = p[i];
            ans = (ans % mod + (cnt[i] % mod * pi % mod) % mod) % mod;
        }
        cout << ans << endl;
    }
    
    return 0;
}