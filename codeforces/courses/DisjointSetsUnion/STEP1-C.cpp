# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const int oo = numeric_limits<int>::max();
int n, m;
string s;

struct DSU {
	int n, comp = n;
	vector<int> p, exp, acc;
    vector<vector<int>> c;
	DSU(int n) : n(n) {
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
        exp.assign(n + 10, 0);
        acc.assign(n + 10, 0);
        for(int i = 0; i < n + 10; i++) c.push_back({i});
	}
	void join(int a, int b){
		a = p[a], b = p[b];
		if (a == b) return;
		if (c[a].size() < c[b].size()) swap(a, b);
		for(int e: c[b])
            exp[e] += acc[b] - acc[a],
            p[e] = a,
            c[a].push_back(e);
        c[b].clear();
		comp--;
	}
};

int main(){
    io_boost;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> s >> u;
        u--;
        if(s == "join") cin >> v, v--, dsu.join(u, v);
        else if(s == "get") cout << dsu.exp[u] + dsu.acc[dsu.p[u]] << endl;
        else{
            cin >> v;
            u = dsu.p[u];
            dsu.acc[u] += v;
        }
    }
    return 0;
}