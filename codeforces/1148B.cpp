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

const int MAXN = 200001;

int n, m, k;
ulli ta, tb;
ulli a[MAXN], b[MAXN];
int main() {
	cin >> n >> m >> ta >> tb >> k;

	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	if(k >= n){
		cout << -1 << endl;
		return 0;
	}

	ulli max = 0;
	for (int i = -1; i < k; ++i){
		auto lb = lower_bound(b, b + m, a[i + 1] + ta);
		int p = lb - b;

		p += k - i - 1;

		if(p >= m){
			cout << -1 << endl;
			return 0;
		}

		if(b[p] + tb > max) max = b[p] + tb;
	}

	cout << max << endl;
	return 0;	
}