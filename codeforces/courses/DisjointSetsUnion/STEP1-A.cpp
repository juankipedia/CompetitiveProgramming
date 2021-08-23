# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n, m;
string s;

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

int main(){
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> s >> u >> v;
        u--;
        v--;
        if(s == "union") dsu.join(u, v);
        else if(dsu.find(u) == dsu.find(v)) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}