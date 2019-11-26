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

int n, m, u;
string s;
long double cost;
map<string, int> names;

bool f(long double G[][30]){
	long double dist[30][30];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dist[i][j] = G[i][j];

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if(dist[i][j] < dist[i][k] * dist[k][j]) dist[i][j] = dist[i][k] * dist[k][j];
	for (int i = 0; i < n; ++i)
		if(dist[i][i] - 1.0L > 0.0000001) return true;
	return false;
}

int main() {
	io_boost;
	int j = 1;
	while(cin >> n and n != 0){
		for (int i = 0; i < n; ++i){
			cin >> s;
			names[s] = i;
		}
		cin >> m;
		long double G[30][30];
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) G[i][j] = 0;
		for (int i = 0; i < m; ++i){
			cin >> s >> cost;
			u = names[s];
			cin >> s;
			G[u][names[s]] = cost;
		}
		if(f(G)) cout << "Case " << j << ": " << "Yes" << endl;
		else cout << "Case " << j << ": " << "No" << endl;
		j++;
	}
    return 0;
}