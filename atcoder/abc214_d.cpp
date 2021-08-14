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
	DSU(int n) : n(n) {
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
	}
	int find(int n) { return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (len[a] < len[b]) swap(a, b);
		len[a] += len[b];
		p[b] = a;
		comp--;
	}
};

int N;

int main(){
    cin >> N;
    vector<tuple<lli, int, int>> edges;
    for(int i = 0; i < N - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(N);
    lli ans = 0;
    for(auto [w, u, v] : edges){
        u = dsu.find(u), v = dsu.find(v);
        ans += w * dsu.len[u] * dsu.len[v];
        dsu.join(u, v);
    }
    cout << ans << endl;
    return 0;
}