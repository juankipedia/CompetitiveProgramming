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

int n, m1, m2;

int main(){
    cin >> n >> m1 >> m2;
    DSU g(n), gp(n);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.join(u, v);
    }

    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        gp.join(u, v);
    }

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            if(g.find(i) != g.find(j) && gp.find(i) != gp.find(j)){
                ans.push_back({i + 1, j + 1});
                g.join(i, j);
                gp.join(i, j);
            }
        }
    cout << ans.size() << endl;
    for(auto &[u, v]: ans) cout << u << " " << v << endl;
    return 0;
}