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

const int MAXN = 1e5;
int n, t, e, a, b, i;


void count_(int v, vector<vector<int>> &g, bool visited[]){
	if(visited[v])
		return;
	visited[v] = true;
	for (const auto &j: g[v]) count_(j, g, visited);
}

int count(vector<vector<int>> &g, bool visited[]){
	int r = 0;
	for (int v = 0; v < n; ++v){
		if(not visited[v]){
			r++;
			count_(v, g, visited);
		}
	}
	return r;
}

int main() {
	cin >> t;
	for (i = 1; i <= t; ++i){
		cin >> n;
		cin >> e;
		bool visited[n] = {false};
		vector<vector<int>> g(n);
		while(e--){
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		cout << count(g, visited) << endl;
	}
    return 0;
}