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

int n, m;
int a[201], b[201], ai, bi;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> ai;
		a[ai] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		cin >> bi;
		b[bi] = 1;
	}

	for (int i = 1; i <= 200; ++i){
		for (int j = 1; j <= 200; ++j){
			if(a[i] == 1 and b[j] == 1 and (i + j >= 201 or a[i + j] != 1 and b[i + j] != 1)){
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
    return 0;
}