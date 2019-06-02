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
typedef std::numeric_limits< double > dbl;

vector<int> pset(3001);

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

int main(){
	int n;
	cin >> n;
	initSet(n);
	int a[n];
	char c;
	for(int i = 0;i < n; i++) cin >> a[i];

	for(int i = 0;i < n; i++){
		for(int j = 0; j < n; j++){ 
			cin >> c;
			if(c == '1') unionSet(i, j);
		}
	}

	for(int i = 0;i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j] and findSet(i) == findSet(j))
				swap(a[i], a[j]);
		}
	}


	for(int i = 0;i < n; i++)
		cout << a[i] << " ";

	cout << endl;
	return 0;
}