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

const int MAXN = 10000;
const int MAXM = 20000;
int n, m, s, t;

vector<int> G[MAXN];
bool visited[MAXN];

bool _dfs(int v, int p,  int &c){
	if(visited[v])
		return false;
	visited[v] = true;
	c++;
	for (const auto & vi: G[v]){
		if(vi != p and not _dfs(vi, v, c)){
			return false;
		}
	}

	return true;
}

bool dfs(){
	int c = 0;
	if(_dfs(0, -1, c) and c == n)
		return true;
	else return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		cin >> s >> t;
		G[s - 1].push_back(t - 1);
		G[t - 1].push_back(s - 1);
	}

	if(n <= m){
		cout << "NO" << endl;
		return 0;
	}
	
	if(dfs()){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
    return 0;
}