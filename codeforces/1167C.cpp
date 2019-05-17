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


vector<int> pset(5 * 1e6 + 1);
unordered_map<int, int> pc;

void initSet(int _size){ 
	pset.resize(_size); 
	for(size_t i = 0; i < _size; i++) 
		pset[i] = i; 
}

int findSet(int i){ 
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}

void unionSet(int i, int j){ 
	pset[findSet(i)] = findSet(j); 
}

bool isSameSet(int i, int j){ 
	return findSet(i) == findSet(j); 
}

int n, m, k, uf, u_i;
int main() {
	cin >> n >> m;
	initSet(n + 1);
	for (int i = 0; i < m; ++i){
		cin >> k;
		if(k > 0)
			cin >> uf;
		for (int j = 1; j < k; ++j){
			cin >> u_i;
			unionSet(uf, u_i);
		}
	}

	for (int i = 1; i <= n; ++i) ++pc[findSet(i)];
	for (int i = 1; i <= n; ++i) cout << pc[findSet(i)] << " ";
	cout << endl;
    return 0;
}