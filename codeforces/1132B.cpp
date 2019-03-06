#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
typedef unsigned long long int ulli;


int main() {
	ulli n, m;
	cin >> n;
	ulli a[n];
	for (ulli i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, std::greater<ulli>());
	cin >> m;
	ulli q;
	ulli s[n];
	s[0] = a[0];
	for (ulli i = 1; i < n; ++i)
		s[i] = a[i] + s[i - 1];

	for (ulli i = 0; i < m; ++i){
		cin >> q;
		ulli r = 0;
		r += s[q - 2];
		r += s[n - 1] - s[q - 2] - a[q - 1];
		cout << r << endl;
	}

    return 0;
}