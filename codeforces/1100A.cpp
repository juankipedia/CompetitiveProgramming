#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int main() {
	io_boost
	int n, k, m = -1, e_t = 0, s_t = 0;
	cin >> n >> k;
	int t[n];
	for (int i = 0; i < n; ++i){
		cin >> t[i];
		if(t[i] == 1)
			e_t ++;
		else
			s_t ++;
	}

	for (int j = 0; j < k; ++j){
		int e = e_t, s = s_t;
		for (int i = j; i < n; i += k) if(t[i] == 1) e--; else s--;
		m = max(m, abs(e - s)); 
	}
	cout << m << endl;
    return 0;
}