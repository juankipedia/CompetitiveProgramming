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

int n, m, l;
bool lb[1001];
bool lbi[1001];
int b, k;
vector<int> s[1001];

bool equal(){
	for (int i = 0; i < m; ++i){
		if(lb[i] != lbi[i])
			return false;	
	}

	return true;
}

bool all_off(){
	for (int i = 0; i < m; ++i){
		if(lb[i])
			return false;	
	}

	return true;
}

int main() {
	cin >> n >> m;
	cin >> l;
	for (int i = 0; i < l; ++i){
		cin >> b;
		lb[b - 1] = true;
		lbi[b - 1] = true;
	}



	ui c = 0;
	bool f = false;
	ui r = c;
	for (int i = 0; i < n; ++i){
		cin >> k;
		for (int j = 0; j < k; ++j){
			cin >> b;
			s[i].push_back(b -  1);
			lb[b - 1] = !lb[b - 1];
		}
		c++;
		if(all_off() and not f){
			f = true;
			r = c;
		}

	}
	if(f) {
		cout << r << endl;
		return 0;
	}
	while(not equal()){
		for (int i = 0; i < n; ++i){
			for (const int &e : s[i]){
				lb[e] = !lb[e];
			}
			c++;
			if(all_off()){
				cout << c << endl;
				return 0;
			}
		}

		if (equal()){
			cout << -1 << endl;
			return 0;
		}

	}

	cout << -1 << endl;
    return 0;
}