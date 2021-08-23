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

const int MAXN = 100005;
int n, m1, m2;
map<int, int> m[MAXN];
set<int> row[MAXN], col[MAXN];

void insert_row(int r1, int r2){
    for(auto e : row[r2]){
        m[r1][e] = m[r2][e];
        row[r1].insert(e);
        col[e].erase(r2);
        col[e].insert(r1);
    }
}
 
void insert_col(int c1, int c2){
    for(auto e : col[c2]){
        m[e][c1] = m[e][c2];
        col[c1].insert(e);
        row[e].erase(c2);
        row[e].insert(c1);
    }
}

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
	if (m1 < m2) swap(g, gp);
	for(int i = 0;i < n; i++){
		int p1 = g.find(i), p2 = gp.find(i);
		m[p1][p2] = i;
		row[p1].insert(p2);
		col[p2].insert(p1);
	}
    set<pair<int, int>> rows;
	for (int i = 0; i < n; i++)
		if(g.find(i) == i)
			rows.insert(make_pair(-row[i].size(),i));
    
    vector<pair<int, int>> ans;
	while(rows.size() > 1){
		int x = rows.begin()->second;
		rows.erase(rows.begin());
		int y = rows.begin()->second;
		rows.erase(rows.begin());
		if(row[x].size() < row[y].size()) swap(x,y);
		auto it = row[x].begin();
		int a = *it, b = *row[y].begin();
		if(a == b) a = *++it;
		ans.push_back(make_pair(m[x][a] + 1, m[y][b] + 1));
		if(col[a].size() < col[b].size()) swap(a,b);
        insert_row(x, y);
        insert_col(a, b);
		rows.insert(make_pair(-row[x].size(),x));
	}
    cout << ans.size() << endl;
    for(auto &[u, v]: ans) cout << u << " " << v << endl;
    return 0;
}

