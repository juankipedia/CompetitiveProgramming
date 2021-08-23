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
	int find(int n) { return p[n] == n ? n : find(p[n]); }
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
    int k;
    cin >> n >> m >> k;
    DSU d(n);
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, u--, v--;

    vector<tuple<int, int, bool>> q;
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> s >> u >> v;
        u--;
        v--;
        q.push_back({u, v, s == "cut" ? 1 : 0});
    }
    reverse(q.begin(), q.end());
    vector<string> ans;
    for(auto &[u, v, c] : q){
        if(c) d.join(u, v);
        else if(d.find(u) == d.find(v)) ans.push_back("YES");
        else ans.push_back("NO");
    }
    reverse(ans.begin(), ans.end());
    for(string &s : ans) cout << s << endl;
    return 0;
}