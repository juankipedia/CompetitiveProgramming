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

size_t N, K, M;
unordered_map<string, int> m;
vector_ulli ks;
void __dft(int n, pair<vector<int>, bool> g[], ulli &c){
	if(g[n].second)
		return;
	g[n].second = true;
	c++;
	for (const int &e : g[n].first) __dft(e, g, c);
}

void dft( pair<vector<int>, bool> g[]){
	ulli c = 0;
	for (int i = 0; i < N; ++i){
		if(not g[i].second){
			c = 0;
			__dft(i, g, c);
			ks.push_back(c);
		}
	}
}

int main() {
	cin >> N >> M >> K;
	pair<vector<int>, bool> g[N] = {make_pair(vector_i(), false)};
	int j = 0;
	string s1, s2;
	for (int i = 0; i < M; ++i){
		cin >> s1 >> s2;
		if(m.find(s1) == m.end()){
			m[s1] = j;
			j++;
		}
		if(m.find(s2) == m.end()){
			m[s2] = j;
			j++;
		}
		g[m[s1]].first.push_back(m[s2]);
		g[m[s2]].first.push_back(m[s1]);
	}	
	dft(g);
	ulli r = 0;

	sort(ks.begin(), ks.end(), std::greater<ulli>());

	for (int i = 0; i < min(K, ks.size()); ++i)
		r += ks[i];
	cout << r << endl;
}