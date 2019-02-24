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

int main() {
	int n;

	cin >> n;
	ui a[n];
	for (int i = 0; i < n; ++i) cin >> a[i]; 
	sort(a, a + n);
	vector_ui r_b;
	vector_ui r_e;
	for (ui i = 0; i < n - 1; ++i){
		if(i % 2 == 0)
			r_b.push_back(a[i]);
		else
			r_e.push_back(a[i]);
	}
	for(const auto &e: r_b) cout << e << " ";
	cout << a[n - 1] << " ";
	for(int i = r_e.size() - 1; i >= 0; i--) cout << r_e[i] << " ";	
	cout << endl;
    return 0;
}