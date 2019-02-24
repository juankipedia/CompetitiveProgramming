#include <bits/stdc++.h>
using namespace std;


int main() {
	int64_t n;
	cin >> n;
	int64_t a_i;
	unordered_map<int64_t, vector<int64_t>> m;
	for (int64_t i = 0; i < 2 * n; ++i){
		cin >> a_i;
		m[a_i].push_back(i);
	}

	int64_t s_p = 0, d_p = 0;
	unsigned long long int r = 0;
	for (unsigned long long int i = 1; i <= n; ++i){
		if(abs(m[i][0] - s_p) + abs(m[i][1] - d_p) <= abs(m[i][1] - s_p) + abs(m[i][0] - d_p)){
			r += abs(m[i][0] - s_p);
			r += abs(m[i][1] - d_p);
			s_p = m[i][0];
			d_p = m[i][1];
		}
		else{
			r += abs(m[i][1] - s_p);
			r += abs(m[i][0] - d_p);
			s_p = m[i][1];
			d_p = m[i][0];
		}
	}

	cout << r << endl;
    return 0;
}