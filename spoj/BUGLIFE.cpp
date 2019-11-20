#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int t, u, v, n, m;

bool is_bipartite_(vector<int> G[], int color[], int src){
	queue<int> q;
	q.push(src);
	color[src] = 1;
	while(not q.empty()){
		int v = q.front();
		q.pop();
		for (const int &u : G[v]){
			if(color[u] == -1){
				q.push(u);
				color[u] = 1 - color[v];
			}
			else if(color[u] == color[v]) return false;
		}
	}
	return true;
}

bool is_bipartite(vector<int> G[]){
	int color[n];
	for (int i = 0; i < n; ++i) color[i] = -1;
	for (int i = 1; i < n; ++i){
		if(color[i] == -1){
			if(not is_bipartite_(G, color, i)) return false;
		}
	}
	return true;
}


int main() {
	cin >> t;
	for (int ti = 1; ti <= t; ++ti){
		cin >> n >> m;
		n ++;
		vector<int> G[n];
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(is_bipartite(G)) cout << "Scenario #" << ti << ":" << endl << "No suspicious bugs found!" << endl;
		else cout << "Scenario #" << ti << ":" << endl << "Suspicious bugs found!" << endl;
	}
    return 0;
}