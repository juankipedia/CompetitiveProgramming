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

int n, m, ai, c = 1, ct = 0;

void insert(int p[]){
	p[ai]++;
	if(p[ai] == c)
		ct ++;
	if (ct == n){
		ct = 0;
		c++;
		for (int i = 1; i <= n; ++i) if(p[i] >= c) ct ++;
		cout << 1;
		return;
	}
	cout << 0;
}

int main() {
	io_boost
	cin >> n >> m;
	if(n == 1){
		for (int i = 0; i < m; ++i){
			cin >> ai;
			cout << 1;
		}

	}
	else{
		int p[n + 1] = {0};
		for (int i = 0; i < m; ++i){
			cin >> ai;
			insert(p);
		}
	}
	cout << endl;
    return 0;
}