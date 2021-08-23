# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

struct DSU {
	int n, comp = n;
	vector<int> p, len;
    vector<vector<int>> c;
	DSU(int n) : n(n){
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
        c.assign(n + 10, vector<int>());
        for(int i = 0; i < n + 10; i++) c[i].push_back(i);
	}
	int find(int n){ return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(len[a] < len[b]) swap(a, b);
		len[a] += len[b];
		for(int e : c[b])
            p[e] = a,
            c[a].push_back(e);
        c[b].clear();

		comp--;
	}
};

const int MAXN = 2e5 + 5;
int n, m, H[MAXN][2];
bool HB[MAXN][2];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> H[i][0] >> H[i][1];
        if(H[i][0] != -1) H[i][0]--;
        if(H[i][1] != -1) H[i][1]--;
    }
    vector<pair<int, int>> q;
    DSU d(n);
    for(int i = 0; i < m; i++){
        int u, h, v;
        cin >> u >> h;
        u--;
        h--;
        v = H[u][h];
        HB[u][h] = true;
        q.push_back({u, v});
    }
    for(int i = 0; i < n; i++){
        if(!HB[i][0] && H[i][0] != -1) d.join(i, H[i][0]);
        if(!HB[i][1] && H[i][1] != -1) d.join(i, H[i][1]);
    }
    reverse(q.begin(), q.end());
    int t = m - 1, ans[n];
    for(int i = 0; i < n; i++) ans[i] = -1;
    for(auto [u, v] : q){
        vector<int> c;
        u = d.find(u);
        v = d.find(v);
        int z = d.find(0); 
        if(u == z && v != z) c = d.c[v];
        else if(v == z && u != z) c = d.c[u];
        for(int e : c) ans[e] = t;
        d.join(u, v);
        t--;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}