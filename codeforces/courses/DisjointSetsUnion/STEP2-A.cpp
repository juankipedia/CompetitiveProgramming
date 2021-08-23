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
	vector<int> p, len, maxi;
	DSU(int n) : n(n){
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
        maxi = p;
	}
	int find(int n){ return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(len[a] < len[b]) swap(a, b);
		maxi[a] = max(maxi[b], maxi[a]);
        len[a] += len[b];
		p[b] = a;
		comp--;
	}
};

int n, m;

int main(){
    io_boost;
    cin >> n >> m;
    DSU d(n);
    string q;
    for(int i = 0, u; i < m; i++){
        cin >> q >> u;
        u--;
        if(q == "-") d.join(u, u + 1);
        else if((d.maxi[d.find(u)] + 1) == (n + 1)) cout << -1 << endl;
        else cout << d.maxi[d.find(u)] + 1 << endl;
    }
    return 0;
}