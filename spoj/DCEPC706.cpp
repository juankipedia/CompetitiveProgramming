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
const int INF = std::numeric_limits<int>::max();
int t, ti, m, n;
string city[202];
int tdist[202][202];
int dist[202][202];

void f(int i, int j){
	queue<pair<pair<int, int>, int>> q;
	q.push({{i, j}, 0});
	vector<pair<int, int>> indexes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	bool visited[m + 2][n + 2];
	for (int i = 0; i < m + 2; ++i)
		for (int j = 0; j < n + 2; ++j) visited[i][j] = false;
	visited[i][j] = true;
	while(not q.empty()){
		pair<pair<int, int>, int> p  = q.front();
		q.pop();
		int ii = p.first.first, jj = p.first.second, d = p.second;
		if(tdist[ii][jj] == ti)
			dist[ii][jj] = max(dist[ii][jj], d);
		else{
			tdist[ii][jj] = ti;
			dist[ii][jj] = d;
		}
		for(const pair<int, int> &e: indexes){
			if(ii + e.first >= 0 and ii + e.first < m + 2 and jj + e.second >= 0 and jj + e.second < n + 2 
				and visited[ii + e.first][jj + e.second] == false and city[ii + e.first][jj + e.second] != '#'){
				q.push({{ii + e.first, jj + e.second}, d + 1});
				visited[ii + e.first][jj + e.second] = true;
			}
		}
	}

	for (int i = 0; i < m + 2; ++i)
		for (int j = 0; j < n + 2; ++j) if(not visited[i][j]) dist[i][j] = INF;
}

int main() {
	io_boost;
	cin >> t;
	for (ti = 1; ti <= t; ++ti){
		cin >> m >> n;
		city[0] = string(n + 2, '.');
		for (int i = 1; i <= m; ++i){
			cin >> city[i];
			city[i] = "." + city[i] + ".";
		}
		city[m + 1] = string(n + 2, '.');

		for (int i = 0; i < m + 2; ++i){
			for (int j = 0; j < n + 2; ++j){
				//cout << city[i][j] << " ";
				if(city[i][j] == '1' or city[i][j] == '2' or city[i][j] == '3')
					f(i, j);
			}
			//cout << endl;
		}

		//cout << endl << endl;
	
		int r = INF;
		for (int i = 0; i < m + 2; ++i){
			for (int j = 0; j < n + 2; ++j){	
				//cout << dist[i][j] << " ";
				if(city[i][j] != '#')
					r = min(r, dist[i][j]);
			}
			//cout << endl;
		}

		cout << r << endl;

	}
    return 0;
}