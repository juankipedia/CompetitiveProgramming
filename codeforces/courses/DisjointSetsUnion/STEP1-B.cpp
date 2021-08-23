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
	vector<int> p, len, mini, maxi;
	DSU(int n) : n(n) {
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
        mini.assign(n + 10, 0);
        maxi.assign(n + 10, 0);
        iota(mini.begin(), mini.end(), 0);
        iota(maxi.begin(), maxi.end(), 0);
	}
	int find(int n) { return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (len[a] < len[b]) swap(a, b);
		len[a] += len[b];
        mini[a] = min(mini[a], mini[b]);
        maxi[a] = max(maxi[a], maxi[b]);
		p[b] = a;
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
        if(s == "union") cin >> v, v--, dsu.join(u, v);
        else v = dsu.find(u), cout << dsu.mini[v] + 1 << " " << dsu.maxi[v] + 1 << " " << dsu.len[v] << endl;
    }
    return 0;
}